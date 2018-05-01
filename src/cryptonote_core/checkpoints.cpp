// Copyright (c) 2014-2018, The Monero Project
// Copyright (c) 2018, SUMOKOIN
// Copyright (c) 2014-2018, Solace Charity Coin Project
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#include "include_base_utils.h"

using namespace epee;

#include "checkpoints.h"

#include "common/dns_utils.h"
#include "include_base_utils.h"
#include <sstream>
#include <random>

namespace
{
  bool dns_records_match(const std::vector<std::string>& a, const std::vector<std::string>& b)
  {
    if (a.size() != b.size()) return false;

    for (const auto& record_in_a : a)
    {
      bool ok = false;
      for (const auto& record_in_b : b)
      {
	if (record_in_a == record_in_b)
	{
	  ok = true;
	  break;
	}
      }
      if (!ok) return false;
    }

    return true;
  }
} // anonymous namespace

namespace cryptonote
{
  //---------------------------------------------------------------------------
  checkpoints::checkpoints()
  {
  }
  //---------------------------------------------------------------------------
  bool checkpoints::add_checkpoint(uint64_t height, const std::string& hash_str)
  {
    crypto::hash h = null_hash;
    bool r = epee::string_tools::parse_tpod_from_hex_string(hash_str, h);
    CHECK_AND_ASSERT_MES(r, false, "Failed to parse checkpoint hash string into binary representation!");

    // return false if adding at a height we already have AND the hash is different
    if (m_points.count(height))
    {
      CHECK_AND_ASSERT_MES(h == m_points[height], false, "Checkpoint at given height already exists, and hash for new checkpoint was different!");
    }
    m_points[height] = h;
    return true;
  }
  //---------------------------------------------------------------------------
  bool checkpoints::is_in_checkpoint_zone(uint64_t height) const
  {
    return !m_points.empty() && (height <= (--m_points.end())->first);
  }
  //---------------------------------------------------------------------------
  bool checkpoints::check_block(uint64_t height, const crypto::hash& h, bool& is_a_checkpoint) const
  {
    auto it = m_points.find(height);
    is_a_checkpoint = it != m_points.end();
    if(!is_a_checkpoint)
      return true;

    if(it->second == h)
    {
      LOG_PRINT_GREEN("CHECKPOINT PASSED FOR HEIGHT " << height << " " << h, LOG_LEVEL_1);
      return true;
    }else
    {
      LOG_ERROR("CHECKPOINT FAILED FOR HEIGHT " << height << ". EXPECTED HASH: " << it->second << ", FETCHED HASH: " << h);
      return false;
    }
  }
  //---------------------------------------------------------------------------
  bool checkpoints::check_block(uint64_t height, const crypto::hash& h) const
  {
    bool ignored;
    return check_block(height, h, ignored);
  }
  //---------------------------------------------------------------------------
  //FIXME: is this the desired behavior?
  bool checkpoints::is_alternative_block_allowed(uint64_t blockchain_height, uint64_t block_height) const
  {
    if (0 == block_height)
      return false;

    auto it = m_points.upper_bound(blockchain_height);
    // Is blockchain_height before the first checkpoint?
    if (it == m_points.begin())
      return true;

    --it;
    uint64_t checkpoint_height = it->first;
    return checkpoint_height < block_height;
  }
  //---------------------------------------------------------------------------
  uint64_t checkpoints::get_max_height() const
  {
    std::map< uint64_t, crypto::hash >::const_iterator highest =
        std::max_element( m_points.begin(), m_points.end(),
                         ( boost::bind(&std::map< uint64_t, crypto::hash >::value_type::first, _1) <
                           boost::bind(&std::map< uint64_t, crypto::hash >::value_type::first, _2 ) ) );
    return highest->first;
  }
  //---------------------------------------------------------------------------
  const std::map<uint64_t, crypto::hash>& checkpoints::get_points() const
  {
    return m_points;
  }

  bool checkpoints::check_for_conflicts(const checkpoints& other) const
  {
    for (auto& pt : other.get_points())
    {
      if (m_points.count(pt.first))
      {
        CHECK_AND_ASSERT_MES(pt.second == m_points.at(pt.first), false, "Checkpoint at given height already exists, and hash for new checkpoint was different!");
      }
    }
    return true;
  }

  bool checkpoints::init_default_checkpoints()
  {
    ADD_CHECKPOINT(1,   "37cc7d14e7e7a55d5fcd8ad7e4431f46059c15eb02b4d99e464a20492c2a2991"); 
	ADD_CHECKPOINT(100,   "6809de1dd47e4a3e69e09df86e7d0ecaa5addf746eff1ba7b5895dc5cd09db8c");
	ADD_CHECKPOINT(200,   "cfa24014114494087092079c20ac8b0438af96bebbc62349a1bd94ecfde3541c");
	ADD_CHECKPOINT(300,   "029c392f87722acd78ca2347b8d00423d087d6a45db0f93dcab346d0e183c11a");
	ADD_CHECKPOINT(400,   "9cb0692dcbc5111595400508ae7ac73e0c86c5b3a4cbc343797988b57bdae58f");
	ADD_CHECKPOINT(500,   "a80561753cd1c4d6ada938bba6b82274ae34ea5ef9dd532321d8712b756ad3e1");
	ADD_CHECKPOINT(1000,   "d6a9f33e2234c59f5b4bdaa17b170c09d4f90b552020086a10758d9fcd1e67cd");
	ADD_CHECKPOINT(2000,   "100c10f9ba239bdc718d5d341c2f23ef988c75c17d126a92976acee6e56d4c35");
	ADD_CHECKPOINT(3000,   "5627b02a01e704a8fc48632249c259b8e859d5b5c3e652989957c0afb497c662");
	ADD_CHECKPOINT(4000,   "44e0d3cdc337ece69dd9f4646b6c58818ce4919ed3dedc6d64b3f5bf69cce4ee");
	ADD_CHECKPOINT(9999,   "795b017f91eb61f2114d22022283d27d210beb6cada568ad8a64de5ef315e41c");
	ADD_CHECKPOINT(10000,   "361edb619a7a9358b81afe9db96f417b9cbc966fe834eb7fc4202fc4d78e7842");
	ADD_CHECKPOINT(15000,   "e89b7143e522422ff90ebeda3f7820e2d9d48145acdeaf6b9f22afafe3aaffda");
	ADD_CHECKPOINT(17500,   "3f8c47f877cd38031c1bf638704bd8f36bb182eaec7b388e4c4b630108156e49");
	ADD_CHECKPOINT(20000,   "0c35b0e2675cd47901b0fa2865d34af922078060f181f5f3b5fa0aec402cf854");
	ADD_CHECKPOINT(25000,   "0741dbde5271a3ec8734b8bfe67c305e14d78b79b7e3f21bf76130dbeda72225");
	ADD_CHECKPOINT(30000,   "d1c9a70e60b6a3c3b2b777aeff0cebd8e73f73de2e104f52eac4911c48889b09");
	
	

    return true;
  }

  bool checkpoints::load_checkpoints_from_json(const std::string json_hashfile_fullpath)
  {
    boost::system::error_code errcode;
    if (! (boost::filesystem::exists(json_hashfile_fullpath, errcode)))
    {
      LOG_PRINT_L1("Blockchain checkpoints file not found");
      return true;
    }

    LOG_PRINT_L1("Adding checkpoints from blockchain hashfile");

    uint64_t prev_max_height = get_max_height();
    LOG_PRINT_L1("Hard-coded max checkpoint height is " << prev_max_height);
    t_hash_json hashes;
    epee::serialization::load_t_from_json_file(hashes, json_hashfile_fullpath);
    for (std::vector<t_hashline>::const_iterator it = hashes.hashlines.begin(); it != hashes.hashlines.end(); )
    {
      uint64_t height;
      height = it->height;
      if (height <= prev_max_height) {
	LOG_PRINT_L1("ignoring checkpoint height " << height);
      } else {
	std::string blockhash = it->hash;
	LOG_PRINT_L1("Adding checkpoint height " << height << ", hash=" << blockhash);
	ADD_CHECKPOINT(height, blockhash);
      }
      ++it;
    }

    return true;
  }

  bool checkpoints::load_checkpoints_from_dns(bool testnet)
  {
    // All SolacePulse domains have DNSSEC on and valid
    static const std::vector<std::string> dns_urls =
    {
      "checkpoints1.solace-coin.com",
      "checkpoints2.solace-coin.com",
      "checkpoints3.solace-coin.com"
    };

    static const std::vector<std::string> testnet_dns_urls = {
    "testpoints.solace.io"
    };

    std::vector<std::vector<std::string> > records;
    records.resize(dns_urls.size());

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, dns_urls.size() - 1);
    size_t first_index = dis(gen);

    bool avail, valid;
    size_t cur_index = first_index;
    do
    {
      std::string url;
      if (testnet)
      {
        url = testnet_dns_urls[cur_index];
      }
      else
      {
        url = dns_urls[cur_index];
      }

      records[cur_index] = tools::DNSResolver::instance().get_txt_record(url, avail, valid);
      if (!avail)
      {
        records[cur_index].clear();
        LOG_PRINT_L2("DNSSEC not available for checkpoint update at URL: " << url << ", skipping.");
      }
      if (!valid)
      {
        records[cur_index].clear();
        LOG_PRINT_L2("DNSSEC validation failed for checkpoint update at URL: " << url << ", skipping.");
      }

      cur_index++;
      if (cur_index == dns_urls.size())
      {
        cur_index = 0;
      }
      records[cur_index].clear();
    } while (cur_index != first_index);

    size_t num_valid_records = 0;

    for( const auto& record_set : records)
    {
      if (record_set.size() != 0)
      {
        num_valid_records++;
      }
    }

    if (num_valid_records < 2)
    {
      LOG_PRINT_L0("WARNING: no two valid SolacePule DNS checkpoint records were received");
      return true;
    }

    int good_records_index = -1;
    for (size_t i = 0; i < records.size() - 1; ++i)
    {
      if (records[i].size() == 0) continue;

      for (size_t j = i + 1; j < records.size(); ++j)
      {
        if (dns_records_match(records[i], records[j]))
        {
    good_records_index = i;
    break;
        }
      }
      if (good_records_index >= 0) break;
    }

    if (good_records_index < 0)
    {
      LOG_PRINT_L0("WARNING: no two SolacePule DNS checkpoint records matched");
      return true;
    }

    for (auto& record : records[good_records_index])
    {
      auto pos = record.find(":");
      if (pos != std::string::npos)
      {
        uint64_t height;
        crypto::hash hash;

        // parse the first part as uint64_t,
        // if this fails move on to the next record
        std::stringstream ss(record.substr(0, pos));
        if (!(ss >> height))
        {
    continue;
        }

        // parse the second part as crypto::hash,
        // if this fails move on to the next record
        std::string hashStr = record.substr(pos + 1);
        if (!epee::string_tools::parse_tpod_from_hex_string(hashStr, hash))
        {
    continue;
        }

        ADD_CHECKPOINT(height, hashStr);
      }
    }
    return true;
  }

  bool checkpoints::load_new_checkpoints(const std::string json_hashfile_fullpath, bool testnet, bool dns)
  {
    bool result;

    result = load_checkpoints_from_json(json_hashfile_fullpath);
    if (dns)
    {
      result &= load_checkpoints_from_dns(testnet);
    }

    return result;
  }
}

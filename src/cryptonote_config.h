// Copyright (c) 2018, The OMBRE Project
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

#pragma once

#include <string>
#include <boost/uuid/uuid.hpp>

#define CRYPTONOTE_DNS_TIMEOUT_MS                       20000

#define CRYPTONOTE_MAX_BLOCK_NUMBER                     500000000
#define CRYPTONOTE_MAX_BLOCK_SIZE                       500000000  // block header blob limit, never used!
#define CRYPTONOTE_GETBLOCKTEMPLATE_MAX_BLOCK_SIZE	    196608 //size of block (bytes) that is the maximum that miners will produce
#define CRYPTONOTE_MAX_TX_SIZE                          1000000000
#define CRYPTONOTE_PUBLIC_ADDRESS_TEXTBLOB_VER          0
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW            60
#define CURRENT_TRANSACTION_VERSION                     2
#define MIN_TRANSACTION_VERSION							2
#define CURRENT_BLOCK_MAJOR_VERSION                     1
#define CURRENT_BLOCK_MINOR_VERSION                     1
#define CRYPTONOTE_V2_POW_BLOCK_VERSION                 3
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT              60*60*2
#define CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE             10
#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW               60

#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V2           60*5
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V3           60*5

#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V2            12

// MONEY_SUPPLY - total number coins to be generated
#define MONEY_SUPPLY                                    ((uint64_t)210000000000000000) // 21 Billion.
#define MONEY_SUPPLY_V5                                 ((uint64_t)105000000000000000) // 10.5 Billion.
#define EMISSION_SPEED_FACTOR                           20
#define FINAL_SUBSIDY                                   ((uint64_t)10000000) // 1 * pow(8, 7)
#define GENESIS_BLOCK_REWARD                            ((uint64_t)10000000)

#define CRYPTONOTE_PROJECT_BLOCK_REWARD                 0.02 // Percentage of the total block reward.
// Initial dev fee - drops down rapidly and averages to CRYPTONOTE_PROJECT_BLOCK_REWARD over time
#define CRYPTONOTE_PROJECT_INITIAL_MULTIPLIER           0.06
#define CRYPTONOTE_PROJECT_BLOCK_ADDRESS                "So1qTor6FMZ1jXmkWSzW8dPVTg8N9YB2tWZfNwBjqG9APDj4wfd5bW4S9rbE6xZBn5evusmmaUaBU9ybETW1mkbq1N1M1szDG"
#define CRYPTONOTE_PROJECT_BLOCK_VIEWKEY                "6017d6363ac3af7445770b44a69884f52af7a4758302d3a28b617271cae10a09"
#define CRYPTONOTE_REWARD_BLOCKS_WINDOW                 60
#define CRYPTONOTE_REWARD_BLOCKS_WINDOW                 60
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE       240 * 1024    // 240KB
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2    300 * 1024    // 300KB
#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE          600
#define CRYPTONOTE_DISPLAY_DECIMAL_POINT                7
// COIN - number of smallest units in one coin
#define COIN                                            ((uint64_t)10000000) // pow(10, 9)

#define FEE_PER_KB                                      ((uint64_t)50)
#define DYNAMIC_FEE_PER_KB_BASE_FEE                     ((uint64_t)50) // 0.0005 * pow(10, 9)
#define DYNAMIC_FEE_PER_KB_BASE_BLOCK_REWARD            ((uint64_t)1000000) // 64 * pow(10, 9)

#define ORPHANED_BLOCKS_MAX_COUNT                       100

#define DIFFICULTY_TARGET                               60  // seconds
#define DIFFICULTY_WINDOW                               93  // blocks
#define DIFFICULTY_WINDOW_V2                            60
#define DIFFICULTY_BLOCKS_COUNT_V2                      DIFFICULTY_WINDOW_V2 + 1
#define DIFFICULTY_LAG                                  15   // !!!
#define DIFFICULTY_CUT                                  60   // timestamps to cut after sorting
#define DIFFICULTY_BLOCKS_COUNT                         DIFFICULTY_WINDOW

#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS       1
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS      DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS

#define DIFFICULTY_BLOCKS_ESTIMATE_TIMESPAN             DIFFICULTY_TARGET //just alias; used by tests


#define BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT          10000  //by default, blocks ids count in synchronizing
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT              10    //by default, blocks count in blocks downloading
#define CRYPTONOTE_PROTOCOL_HOP_RELAX_COUNT             3      //value of hop, after which we use only announce of new block

#define CRYPTONOTE_MEMPOOL_TX_LIVETIME                  86400 //seconds, one day
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME   604800 //seconds, one week

#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT           100

#define P2P_LOCAL_WHITE_PEERLIST_LIMIT                  1000
#define P2P_LOCAL_GRAY_PEERLIST_LIMIT                   5000

#define P2P_DEFAULT_CONNECTIONS_COUNT                   10
#define P2P_DEFAULT_HANDSHAKE_INTERVAL                  60           //seconds
#define P2P_DEFAULT_PACKET_MAX_SIZE                     50000000     //50000000 bytes maximum packet size
#define P2P_DEFAULT_PEERS_IN_HANDSHAKE                  250
#define P2P_DEFAULT_CONNECTION_TIMEOUT                  5000       //5 seconds
#define P2P_DEFAULT_PING_CONNECTION_TIMEOUT             2000       //2 seconds
#define P2P_DEFAULT_INVOKE_TIMEOUT                      60*2*1000  //2 minutes
#define P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT            5000       //5 seconds
#define P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT       70

#define P2P_FAILED_ADDR_FORGET_SECONDS                  (60*60)     //1 hour
#define P2P_IP_BLOCKTIME                                (60*60*24)  //24 hour
#define P2P_IP_FAILS_BEFORE_BLOCK                       10
#define P2P_IDLE_CONNECTION_KILL_INTERVAL               (5*60)		//5 minutes

#define P2P_SUPPORT_FLAG_FLUFFY_BLOCKS                  0x01
#define P2P_SUPPORT_FLAGS                               P2P_SUPPORT_FLAG_FLUFFY_BLOCKS

#define ALLOW_DEBUG_COMMANDS

#define CRYPTONOTE_NAME                                 "solace"
#define CRYPTONOTE_POOLDATA_FILENAME                    "poolstate.bin"
#define CRYPTONOTE_BLOCKCHAINDATA_FILENAME              "blockchain.bin"
#define CRYPTONOTE_BLOCKCHAINDATA_TEMP_FILENAME         "blockchain.bin.lock"
#define P2P_NET_DATA_FILENAME                           "p2pstate.bin"
#define MINER_CONFIG_FILE_NAME                          "miner_conf.json"

#define THREAD_STACK_SIZE                               5 * 1024 * 1024

// coin emission change interval/speed configs
#define COIN_EMISSION_MONTH_INTERVAL                    2  // months to change emission speed
#define COIN_EMISSION_HEIGHT_INTERVAL                   ((uint64_t) (COIN_EMISSION_MONTH_INTERVAL * (30.4375 * 24 * 3600) / DIFFICULTY_TARGET)) // calculated to # of heights to change emission speed
#define PEAK_COIN_EMISSION_YEAR                         2
#define PEAK_COIN_EMISSION_HEIGHT                       ((uint64_t) (((12 * 30.4375 * 24 * 3600)/DIFFICULTY_TARGET) * PEAK_COIN_EMISSION_YEAR)) // = (# of heights emmitted per year) * PEAK_COIN_EMISSION_YEAR

#define DEFAULT_MIXIN                                   2     // default & minimum mixin allowed
#define MAX_MIXIN                                       120

#define TRANSACTION_SIZE_LIMIT                          ((uint64_t) ((CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 110 / 100) - CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE))
#define TRANSACTION_SIZE_LIMIT_V2                       ((uint64_t) ((CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2 * 125 / 100) - CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE))
#define BLOCK_SIZE_GROWTH_FAVORED_ZONE                  ((uint64_t) (CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 4))
#define BLOCK_SIZE_GROWTH_FAVORED_ZONE_V2               ((uint64_t) (CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2 * 4))

// New constants are intended to go here
namespace config
{
  uint64_t const DEFAULT_FEE_ATOMIC_XMR_PER_KB = 500; // Just a placeholder!  Change me!
  uint8_t const FEE_CALCULATION_MAX_RETRIES = 10;
  uint64_t const DEFAULT_DUST_THRESHOLD = ((uint64_t)10000000); // pow(10, 7)
  uint64_t const BASE_REWARD_CLAMP_THRESHOLD = ((uint64_t)100000); // pow(10, 5)
  std::string const P2P_REMOTE_DEBUG_TRUSTED_PUB_KEY = "";

  uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x1a9a;            // So
  uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x6599; // Si
  uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 0x7c18;         // Sa
  uint16_t const P2P_DEFAULT_PORT = 19798;
  uint16_t const RPC_DEFAULT_PORT = 19799;

  boost::uuids::uuid const NETWORK_ID = { {
      0x44, 0xca, 0xf1, 0xb2, 0xf1, 0xc1, 0xfc, 0x42, 0x1a, 0xdf, 0x43, 0x4d, 0x4f, 0x42, 0x11, 0x41
    } }; // Bender's nightmare
  std::string const GENESIS_TX = "013c01ff000180ade20402519dcc58426ab094ccd3c1906578918f50f4b34c9bdcfde9d653f70d66553c772101ea1b88f65c64b86ec9b0aec5ef681ca03556b7acc0db3b1e803df3202ad6e536";
  uint32_t const GENESIS_NONCE = 10000;

  namespace testnet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x211f;            // Te
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x629f; // Ti
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 0x59a0;         // Ts
    //uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_SUBADDRESS_BASE58_PREFIX = 0x17b51a; // Susi
    uint16_t const P2P_DEFAULT_PORT = 29789;
    uint16_t const RPC_DEFAULT_PORT = 29700;
    boost::uuids::uuid const NETWORK_ID = { {
        0xc2, 0x0c, 0x06, 0xdf, 0xce, 0xfc, 0x7c, 0x27, 0xcc, 0x2c, 0xc2, 0xf2, 0xc1, 0x44, 0x44, 0x43
      } }; // Bender's daydream
    std::string const GENESIS_TX = "013c01ff000180ade20402634166d5774918c742008022881ebab130d18a283add08939d51283b16eb689c2101ba54c1a477a2d8ff8a0e107be277b51f986ec03efb813e34bff9948cac2a485a";
    uint32_t const GENESIS_NONCE = 10001;
  }
}

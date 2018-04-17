# SolaceCoin

## Development Resources

- Web: [www.solace-coin.com](http://solace-coin.com)
- GitHub: [https://github.com/schmeckles22/SolaceCoin](https://github.com/schmeckles22/SolaceCoin)

## Introduction

SolaceCoin is a cryptonote currency and an indirect for of the well-known Monero currency. Inherited from Monero are strong security, privacy and untraceability features that form a solid basis for further development. Our mission is to enhance the cryptonote protocol to provide a **lightweight**, **secure**, **well maintained** and **actively developed** (no-nonsense) coin.

Some main differences compared to other cryptonote coins are:

 - We use a 60 second block window which reduce transaction times
 - We enforce a minimum transaction mixin of 10 to fight blockchain analysis which could compromise privacy
 - We actively cooperate with other cryptonote coins and do not treat them as competition.


## Development funding

We do not have a premine. Instead we have a project development reward that causes coins to unlock with every block that is found. The algorithm (see below) will start with unlocking 6% of the block reward but gradually reduces to 0% in the next 10 years.  In total a maximum of 2% of the total coin supply will be unlocked for development.

```
f(x) = 0.06 * (1 - sqrt(x)) where x = current_supply / max_supply S.T. current_supply <= max_supply
```

The development fee will be used to pay for development, exchanges and marketing.

## Coin Supply & Emission

- **Total supply**: **21,000,000,000** coins in first 20 years which is followed by a tail emission each year for inflation.
- **Coin symbol**: **SOLACE**
- **Coin Units**:
  + 1 Nano-Solace &nbsp;= 0.0000001 **SOLACE** (10<sup>-7</sup> - _the smallest coin unit_)
  + 1 Micro-Solace = 0.0001 **SOLACE** (10<sup>-4</sup>)
  + 1 Milli-Solace = 0.1 **SOLACE** (10<sup>-1</sup>)
- **Hash algorithm**: CryptoNight (Proof-Of-Work)
- **Emission scheme**: Solace's block reward changes _every 6-months_ as the following "Camel" distribution* (inspired by _real-world mining production_ like of crude oil, coal etc. that is often slow at first,
accelerated in the next few years before declined and depleted). This great emission scheme was first introduced in Sumokoin.

## Versions

| Fork Date              | Consensus version | Minimum Solace Version | Recommended Solace Version | Name/Details            |  
| ----------------- | ----------------- | ---------------------- | -------------------------- | ------------------ |
| 2018-04-11        | v1        | v0.1.0                 | v0.1.0                    | "Colossus of Rhodes" / First version  |
| 2018-04-12        | v2        | v0.1.1                 | v0.1.1                    | "Colossus of Rhodes" / Hard fork to solve transaction fees |
| 2018-04-19        | v3        | v0.2.0                 | v0.2.0                    | "Hanging Gardens of Babylon" / ASIC Resistance - CryptoNight-Heavy |


## Roadmap 2018
Quarter 2
-Launch SolanceCoin - Completed
-Completion of the SolaceCoin Website
-GUI Wallet
-Web Wallet
-Exchange listing
-Charity voting website completion

Quarter 3
-Mobile Wallets
-Medical Crowdfunding by Solace
-Add more developers to the team
-More Exchange listings
-Mine for your charity script


## About this Project

SolaceCoin is a cryptocurrency with a difference and does exactly what the name says.
Definition of Solace “comfort or consolation in a time of great distress or sadness.”

SolaceCoin has two functions

1) Helping charities to help others in need of medical attention but cannot afford it – Please read below.
2) Serving as a currency for daily usage


## License

Please view [LICENSE](LICENSE)

[![License](https://img.shields.io/badge/license-BSD3-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)

## How to get started with SolaceCoin Wallet

-Download and extract the latest zip file for Solace
-Start solaced.exe . This will take approximately an hour or more to synchronize the blockchain. On successful completion, you will see a green message "SYNCHRONIZED".
-Start solace-wallet-cli.exe to create a wallet. Please ensure to keep the wallet key and seed words in a safe location.
-Once your wallet address is ready, you can start mining, by referring to one of the pools listed on the website. https://www.solace-coin.com/

Good Luck!

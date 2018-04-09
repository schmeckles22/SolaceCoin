# SolaceCoin

## Development Resources

- Web: [www.comingsoon.com](https://www.comingsoon.com)
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

- **Total supply**: **1,000,000,000** coins in first 20 years which is followed by a tail emission each year for inflation.
- **Coin symbol**: **OMB**
- **Coin Units**:
  + 1 Nano-Solace &nbsp;= 0.000000001 **SOL** (10<sup>-9</sup> - _the smallest coin unit_)
  + 1 Micro-Solace = 0.000001 **SOL** (10<sup>-6</sup>)
  + 1 Milli-Solace = 0.001 **SOL** (10<sup>-3</sup>)
- **Hash algorithm**: CryptoNight (Proof-Of-Work)
- **Emission scheme**: Solace's block reward changes _every 6-months_ as the following "Camel" distribution* (inspired by _real-world mining production_ like of crude oil, coal etc. that is often slow at first,
accelerated in the next few years before declined and depleted). This great emission scheme was first introduced in Sumokoin.

## Roadmap 2018



## About this Project



## License

Please view [LICENSE](LICENSE)

[![License](https://img.shields.io/badge/license-BSD3-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)


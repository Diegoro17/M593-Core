# M593 consensus specification (development draft)

This document records the intended rules being implemented in code. Values are
not final for public mainnet until the genesis block and reserve scripts are
generated and independently reviewed.

## Monetary units

- Display unit: M593
- Base unit: mico
- Precision: 8 decimal places
- Consensus monetary ceiling: 593,000,000 M593

## Distribution target

| Allocation | Percentage | Amount |
|---|---:|---:|
| Proof-of-work mining | 92% | 545,560,000 M593 |
| Public adoption reserve | 5% | 29,650,000 M593 |
| Development team reserve | 3% | 17,790,000 M593 |

The reserve allocations must use visible on-chain scripts and a documented
release schedule. No private or hidden premine is permitted.

## Mining schedule

- Proof of work: KAWPOW, intended for commodity GPUs
- Target spacing: 60 seconds
- Slow start: blocks 1 through 129,599
- Full first-era subsidy: 138.63591933 M593
- Halving interval: 2,000,000 blocks
- Coinbase maturity: 60 blocks

The full subsidy differs slightly from the earlier paper estimate because the
implemented calculation accounts for integer base-unit rounding. Its complete
schedule remains just below the 545,560,000 M593 mining allocation.

## Network identity

| Network | P2P port | RPC port | Message start |
|---|---:|---:|---|
| Mainnet | 5933 | 5932 | 4d 35 39 33 |
| Testnet | 15933 | 15932 | 6d 35 39 74 |
| Regtest | 25933 | 25932 | fa 59 33 bf |

DNS seeds and fixed seeds intentionally remain empty during private development.

## Launch gate

A public launch is prohibited until unique genesis hashes, reserve scripts and
keys, seed nodes, reproducible builds, tests, and an external security review
are complete.

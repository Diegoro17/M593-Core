M593 Core
=========

M593 Core is the reference implementation of the M593 peer-to-peer blockchain.
It is being developed from the MIT-licensed Ravencoin Core codebase so it can
reuse the audited UTXO transaction model and GPU-oriented KAWPOW implementation.

Current status
--------------

This repository is under active development. The `m593-dev` branch contains
the first real consensus changes, but it is **not a public mainnet release yet**.
Do not buy, sell, or represent test coins as having monetary value.

Implemented in the first development stage:

- Eight decimal places (`1 M593 = 100,000,000` base units).
- Consensus monetary ceiling of 593,000,000 M593.
- GPU-oriented KAWPOW code inherited from the upstream implementation.
- One-minute target block spacing.
- 90-day / 129,600-block gradual mining start.
- Initial full subsidy of 138.63591933 M593.
- Subsidy halving every 2,000,000 blocks.
- Coinbase maturity of 60 blocks.
- Independent P2P/RPC ports and message-start bytes.
- Mainnet address prefix intended to produce M-prefixed addresses.
- Executable names: `m593d`, `m593-cli`, `m593-tx`, and `m593-qt`.

Planned before the first testnet
--------------------------------

- Generate and lock unique mainnet, testnet, and regtest genesis blocks.
- Activate KAWPOW under the final genesis rules.
- Replace every inherited checkpoint, seed, burn address, icon, translation,
  application identifier, and data-directory reference.
- Implement and test the transparent adoption/team reserve schedule.
- Add seed nodes and reproducible signed releases.
- Complete security review and multi-node/GPU testing.

Branches
--------

- `master`: untouched upstream baseline.
- `m593-dev`: M593 development work.
- Future release branches/tags will only be created after test validation.

Building
--------

The project uses the inherited GNU autotools and depends build systems. An
experimental GitHub Actions workflow is included to cross-compile Windows
binaries. A successful build proves that the source compiles; it does not mean
that the public network is ready.

License
-------

M593 Core remains available under the MIT License. Upstream copyright notices
and attribution are preserved.

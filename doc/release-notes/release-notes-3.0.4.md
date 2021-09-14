SEED2NEED Core version 3.0.4 is now available from:

  <https://github.com/seed2need-project/seed2need/releases>

This is a new minor-revision version release, including various bug fixes and
performance improvements, as well as updated translations.

Please report bugs using the issue tracker at github:

  <https://github.com/seed2need-project/seed2need/issues>


Mandatory Update
==============

SEED2NEED Core v3.0.4 is a mandatory update for all users. This release contains various updates/fixes pertaining to the zSILO protocol, supply tracking, block transmission and relaying, as well as usability and quality-of-life updates to the GUI.

Users will have a grace period to update their clients before versions prior to this release are no longer allowed to connect to this (and future) version(s).


How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely shut down (which might take a few minutes for older versions), then run the installer (on Windows) or just copy over /Applications/SEED2NEED-Qt (on Mac) or seed2needd/seed2need-qt (on Linux).


Compatibility
==============

SEED2NEED Core is extensively tested on multiple operating systems using
the Linux kernel, macOS 10.8+, and Windows Vista and later.

Microsoft ended support for Windows XP on [April 8th, 2014](https://www.microsoft.com/en-us/WindowsForBusiness/end-of-xp-support),
No attempt is made to prevent installing or running the software on Windows XP, you
can still do so at your own risk but be aware that there are known instabilities and issues.
Please do not report issues about Windows XP to the issue tracker.

SEED2NEED Core should also work on most other Unix-like systems but is not
frequently tested on them.

### :exclamation::exclamation::exclamation: MacOS 10.13 High Sierra :exclamation::exclamation::exclamation:

**Currently there are issues with the 3.0.x gitian releases on MacOS version 10.13 (High Sierra), no reports of issues on older versions of MacOS. As such, a High Sierra Only version is included below.**


Notable Changes
===============

Refactoring of zSilo Spend Validation Code
---------------------
zSilo spend validation was too rigid and did not give enough slack for reorganizations. Many staking wallets were unable to reorganize back to the correct blockchain when they had an orphan stake which contained a zSilo spend. zSilo double spending validation has been refactored to properly account for reorganization.

Money Supply Calculation Fix
---------------------
Coin supply incorrectly was counting spent zSilo as newly minted coins that are added to the coin supply, thus resulting in innacurate coin supply data.

The coin supply is now correctly calculated. If a new wallet client is synced from scratch or if `-reindex=1` is used then the correct money supply will be calculated. If neither of these two options are used, the wallet client will automatically reindex the money supply calculations upon the first time opening the software after updating to v3.0.4. The reindex takes approximately 10-60 minutes depending on the hardware used. If the reindex is exited mid-process, it will continue where it left off upon restart.

Better Filtering of Transactions in Stake Miner
---------------------
The stake miner code now filters out zSilo double spends that were on rare occasions being slipped into blocks (and being rejected by peers when broadcast to the network).

More Responsive Shutdown Requests
---------------------
When computationally expensive accumulator calculations are being performed and the user requests to close the application, the wallet will exit much sooner than before.

More Extensive Display of zSilo Confirmation/Maturity Status
---------------------
Within the Privacy Dialog of the QT wallet, the _Zerocoin Stats_ section now displays both the confirmation and maturity status of minted zSilo's. Previously this was only able to be viewed within the zSilo Control dialog. The main Overview tab of the QT wallet now splits zSilo balance into subcategories: _Unconfirmed_, _Immature_, and _Mature_.

3.0.4 Change log
=================

Detailed release notes follow. This overview includes changes that affect
behavior, not code moves, refactors and string updates. For convenience in locating
the code changes and accompanying discussion, both the pull request and
git merge commit are mentioned.

### P2P Protocol and Network Code
- #294 `27c0943` Add additional checks for txid for zsilo spend. (presstab)
- #301 `b8392cd` Refactor zSilo tx counting code. Add a final check in ConnectBlock() (presstab)
- #306 `77dd55c` [Core] Don't send not-validated blocks (Mrs-X)
- #312 `5d79bea` [Main] Update last checkpoint data (Fuzzbawls)
- #325 `7d98ebe` Reindex zSilo blocks and correct stats. (presstab)
- #327 `aa1235a` [Main] Don't limit zSILO spends from getting into the mempool (Fuzzbawls)
- #329 `19b38b2` Update checkpoints. (presstab)
- #331 `b1fb710` [Consensus] Bump protocol. Activate via Spork 15. (rejectedpromise)

### Wallet
- #308 `bd8a982` [Minting] Clear mempool after invalid block from miner (presstab)
- #316 `ed192cf` [Minting] Better filtering of zSilo serials in miner. (presstab)

### GUI
- #309 `f560ffc` [UI] Better error message when too much inputs are used for spending zSILO (Mrs-X)
- #317 `b27cb72` [UI] Wallet repair option to resync from scratch (Mrs-X)
- #323 `2b648be` [UI] Balance fix + bubble-help + usability improvements (Mrs-X)
- #324 `8cdbb5d` disable negative confirmation numbers. (Mrs-X)

### Build System
- #322 `a91feb3` [Build] Add compile/link summary to configure (Fuzzbawls)

### Miscellaneous
- #298 `3580394` Reorg help to stop travis errors (Jon Spock)
- #302 `efb648b` [Cleanup] Remove unused variables (rejectedpromise)
- #307 `dbd801d` Remove hard-coded GIT_ARCHIVE define (Jon Spock)
- #314 `f1c830a` Fix issue causing crash when seed2needd --help was invoked (Jon Spock)
- #326 `8b6a13e` Combine 2 LogPrintf statement to reduce debug.log clutter (Jon Spock)
- #328 `a6c18c8` [Main] SEED2NEED not responding on user quitting app (Aaron Langford)


Credits
=======

Thanks to everyone who directly contributed to this release:
- Fuzzbawls
- Jon Spock
- Mrs-X
- furszy
- presstab
- rejectedpromise
- aaronlangford31

As well as everyone that helped translating on [Transifex](https://www.transifex.com/projects/p/seed2need-project-translations/).

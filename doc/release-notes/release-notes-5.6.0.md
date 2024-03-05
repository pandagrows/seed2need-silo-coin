SEED2NEED Core version *v5.6.0* is now available from:  <https://github.com/seed2need-project/seed2need/releases>

This is a new major version release, including various bug fixes and performance improvements, as well as updated translations.

Please report bugs using the issue tracker at github: <https://github.com/seed2need-project/seed2need/issues>


How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely shut down (which might take a few minutes for older versions), then run the installer (on Windows) or just copy over /Applications/SEED2NEED-Qt (on Mac) or seed2needd/seed2need-qt (on Linux).

Notable Changes
==============

(Developers: add your notes here as part of your pull requests whenever possible)


### Deprecated autocombinerewards RPC Command

The `autocombinerewards` RPC command was soft-deprecated in v5.3.0 and replaced with explicit setter/getter commands `setautocombinethreshold`/`getautocombinethreshold`. SEED2NEED Core, by default, will no longer accept the `autocombinerewards` command, returning a deprecation error, unless the `seed2needd`/`seed2need-qt` is started with the `-deprecatedrpc=autocombinerewards` option.

This command will be fully removed in v6.0.0.

### Shield address support for RPC label commands

The `setlabel` RPC command now supports a shield address input argument to allow users to set labels for shield addresses. Additionally, the `getaddressesbylabel` RPC command will also now return shield addresses with a matching label.

### Specify optional label for getnewshieldaddress

The `getnewshieldaddress` RPC command now takes an optional argument `label (string)` to denote the desired label for the generated address.

### New getnewexchangeaddress RPC Command

The `getnewexchangeaddress` RPC command has been introduced to create an essentially fully Transparent address to disallow deshielding to in compliance for exchanges. It takes an optional `label (string)` to set a label for the address if necessary. Functionality is the same comparitively to `getnewaddress`, `getnewstakingaddress` and `getnewshieldaddress`

| Command Name | Purpose | Requires Unlocked Wallet? |
| ------------ | ------- | ------------------------- |
| `getnewexchangeaddress` | Creates a new exchange address | Yes |

Command is detailed below:

* `getnewexchangeaddress`
  ```
  Returns a new exchange address for receiving payments.

  Result:
  "address"    (string) The new exchange address.
  ```

P2P connection management
--------------------------

- Peers manually added through the addnode option or addnode RPC now have their own
  limit of sixteen connections which does not compete with other inbound or outbound
  connection usage and is not subject to the maxconnections limitation.

- New connections to manually added peers are much faster.

*version* Change log
==============

Detailed release notes follow. This overview includes changes that affect behavior, not code moves, refactors and string updates. For convenience in locating the code changes and accompanying discussion, both the pull request and git merge commit are mentioned.

### Core Features

### Build System

### P2P Protocol and Network Code

### GUI

### RPC/REST
- #2895 Exchange Address `getnewexchangeaddress` (Liquid369) 

### Wallet

### Miscellaneous

## Credits

Thanks to everyone who directly contributed to this release:


As well as everyone that helped translating on [Transifex](https://www.transifex.com/projects/p/seed2need-project-translations/), the QA team during Testing and the Node hosts supporting our Testnet.

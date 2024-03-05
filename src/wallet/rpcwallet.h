// Copyright (c) 2016-2021 The Bitcoin Core developers
// Copyright (c) 2021 The SEED2NEED Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef SEED2NEED_WALLET_RPCWALLET_H
#define SEED2NEED_WALLET_RPCWALLET_H

#include <string>

class CRPCTable;
class CWallet;
class JSONRPCRequest;

void RegisterWalletRPCCommands(CRPCTable &tableRPC);

/**
 * Figures out what wallet, if any, to use for a JSONRPCRequest.
 *
 * @param[in] request JSONRPCRequest that wishes to access a wallet
 * @return nullptr if no wallet should be used, or a pointer to the CWallet
 */
CWallet* GetWalletForJSONRPCRequest(const JSONRPCRequest& request);

std::string HelpRequiringPassphrase(CWallet* const pwallet);
bool EnsureWalletIsAvailable(CWallet* const pwallet, bool avoidException);
void EnsureWalletIsUnlocked(CWallet* const pwallet, bool fAllowAnonOnly = false);

#endif //SEED2NEED_WALLET_RPCWALLET_H

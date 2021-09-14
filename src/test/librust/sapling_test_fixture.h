// Copyright (c) 2020 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or https://www.opensource.org/licenses/mit-license.php.

#ifndef SEED2NEED_SAPLING_TEST_FIXTURE_H
#define SEED2NEED_SAPLING_TEST_FIXTURE_H

#include "test/test_seed2need.h"

/**
 * Testing setup that configures a complete environment for Sapling testing.
 */
struct SaplingTestingSetup : public TestingSetup {
    SaplingTestingSetup();
    ~SaplingTestingSetup();
};


#endif //SEED2NEED_SAPLING_TEST_FIXTURE_H

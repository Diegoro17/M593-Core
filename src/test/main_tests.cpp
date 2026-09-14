// Copyright (c) 2014-2016 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Raven Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "validation.h"
#include "net.h"

#include "test/test_raven.h"

#include <boost/signals2/signal.hpp>
#include <boost/test/unit_test.hpp>

BOOST_FIXTURE_TEST_SUITE(main_tests, TestingSetup)

    BOOST_AUTO_TEST_CASE(m593_block_subsidy_test)
    {
        BOOST_TEST_MESSAGE("Running M593 Block Subsidy Test");

        const auto chainParams = CreateChainParams(CBaseChainParams::MAIN);
        const Consensus::Params& consensus = chainParams->GetConsensus();
        const CAmount baseSubsidy = 13863591933;

        BOOST_CHECK_EQUAL(consensus.nSubsidyHalvingInterval, 2000000);
        BOOST_CHECK_EQUAL(GetBlockSubsidy(0, consensus), 0);
        BOOST_CHECK_EQUAL(GetBlockSubsidy(1, consensus), baseSubsidy / 129600);
        BOOST_CHECK(GetBlockSubsidy(64800, consensus) < baseSubsidy);
        BOOST_CHECK_EQUAL(GetBlockSubsidy(129600, consensus), baseSubsidy);
        BOOST_CHECK_EQUAL(GetBlockSubsidy(1999999, consensus), baseSubsidy);
        BOOST_CHECK_EQUAL(GetBlockSubsidy(2000000, consensus), baseSubsidy / 2);
        BOOST_CHECK_EQUAL(GetBlockSubsidy(64 * consensus.nSubsidyHalvingInterval, consensus), 0);
    }

    BOOST_AUTO_TEST_CASE(m593_mining_allocation_limit_test)
    {
        BOOST_TEST_MESSAGE("Running M593 Mining Allocation Limit Test");

        const auto chainParams = CreateChainParams(CBaseChainParams::MAIN);
        const Consensus::Params& consensus = chainParams->GetConsensus();
        const int slowStartBlocks = 129600;
        CAmount total = 0;

        for (int height = 1; height < slowStartBlocks; ++height) {
            total += GetBlockSubsidy(height, consensus);
        }

        total += GetBlockSubsidy(slowStartBlocks, consensus) *
                 (consensus.nSubsidyHalvingInterval - slowStartBlocks);

        for (int halving = 1; halving < 64; ++halving) {
            const int height = halving * consensus.nSubsidyHalvingInterval;
            const CAmount subsidy = GetBlockSubsidy(height, consensus);
            if (subsidy == 0)
                break;
            total += subsidy * consensus.nSubsidyHalvingInterval;
        }

        const CAmount miningAllocation = 545560000LL * COIN;
        BOOST_CHECK(total <= miningAllocation);
        BOOST_CHECK(miningAllocation - total < COIN);
        BOOST_CHECK(MoneyRange(total));
    }

    bool ReturnFalse()
    { return false; }

    bool ReturnTrue()
    { return true; }

    BOOST_AUTO_TEST_CASE(combiner_all_test)
    {
        BOOST_TEST_MESSAGE("Running Combiner All Test");

        boost::signals2::signal<bool(), CombinerAll> Test;
        BOOST_CHECK(Test());
        Test.connect(&ReturnFalse);
        BOOST_CHECK(!Test());
        Test.connect(&ReturnTrue);
        BOOST_CHECK(!Test());
        Test.disconnect(&ReturnFalse);
        BOOST_CHECK(Test());
        Test.disconnect(&ReturnTrue);
        BOOST_CHECK(Test());
    }

BOOST_AUTO_TEST_SUITE_END()

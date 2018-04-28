#include "maintests.h"

int fees = 2;

void MainTests::testGetProofOfWorkReward()
{
	CBlockIndex* prevBlk = new CBlockIndex();

	// - [] From block 14 to 120 000 POW block reward is 100 BSX per block
	prevBlk->nHeight = 14;
	pindexBest = prevBlk;

	QCOMPARE(GetProofOfWorkReward(fees), (int64_t)(100 * COIN + fees));
	pindexBest->nHeight = 119998;

	QCOMPARE(GetProofOfWorkReward(fees), (int64_t)(100 * COIN + fees));

	// From block 120 001 to block 200 000 POW block reward is 50 BSX per block
	pindexBest->nHeight= 120001;
	QCOMPARE(GetProofOfWorkReward(fees), (int64_t)(50 * COIN + fees));

}

void MainTests::testGetProofOfStakeReward()
{
	CBlockIndex* prevBlk = new CBlockIndex();
	pindexBest = prevBlk;
	//nCoinAge --> Formula: Coins * daysElapsed

	// - [] From block 1 to 120 000 POS is 10% annually
	pindexBest->nHeight = 14;
	int64_t nCoinAge = 50 * 365 ;
	QCOMPARE(GetProofOfStakeReward(nCoinAge, fees), (int64_t)5+fees);

	// - [] From block 120 001 to 200 000 POS is 50% annually
	pindexBest->nHeight = 120002;
	nCoinAge = 50 * 365 ;
	QCOMPARE(GetProofOfStakeReward(nCoinAge, fees), (int64_t)25+fees);

	// - [] From block 200 001 to 1 000 000 POS is 1000% annually
	pindexBest->nHeight = 200001;
	nCoinAge = 50 * 365 ;
	QCOMPARE(GetProofOfStakeReward(nCoinAge, fees), (int64_t)500+fees);

	// - [] After block 1 000 001 POS will be 10% annually forever
	pindexBest->nHeight = 1000001;
	nCoinAge = 50 * 365 ;
	QCOMPARE(GetProofOfStakeReward(nCoinAge, fees), (int64_t)5+fees);
}

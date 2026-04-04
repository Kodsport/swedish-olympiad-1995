#include "validator.h"

#include <numeric>

void run() {
	int n = Int(1, 15);
	Endl();

	vector<int> piles = SpacedInts(n, 1, 50);
	assert(std::accumulate(piles.begin(), piles.end(), 0) <= 50);
}

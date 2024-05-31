#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

TEST(SimilarityCheck, PointMaxforEqualLength) {
	SimilarityChecker sc;
	int result = sc.doCheck("ab", "cd");
	EXPECT_EQ(60, result);
}
#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

TEST(SimilarityCheck, PointMaxforEqualLength) {
	SimilarityChecker sc;
	int result = sc.countString("ab", "cd");
	EXPECT_EQ(60, result);
}

TEST(SimilarityCheck, PointZeroforDoubleLength) {
	SimilarityChecker sc;
	int result = sc.countString("abcd", "cd");
	EXPECT_EQ(0, result);
}

TEST(SimilarityCheck, PointforDiffLength) {
	SimilarityChecker sc;
	int result = sc.countString("abcd", "bcd");
	EXPECT_EQ(40, result);
}

TEST(SimilarityCheck, CheckAlpha) {
	SimilarityChecker sc;
	int result = sc.countAlpha("ASD", "DSA");
	EXPECT_EQ(40, result);
	result = sc.countAlpha("A", "BB");
	EXPECT_EQ(0, result);
}

TEST(SimilarityCheck, CheckAlphaSubpoint) {
	SimilarityChecker sc;
	int result = sc.countAlpha("AA", "AAE");
	EXPECT_EQ(20, result);
}

TEST(SimilarityCheck, CheckInvalid) {
	SimilarityChecker sc;
	int result = sc.countAlpha("asd", "dsa");
}
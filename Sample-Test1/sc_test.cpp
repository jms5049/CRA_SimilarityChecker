#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

class SimilarityCheckFixture : public testing::Test {
public:
	SimilarityChecker sc;
	int result;
};

TEST_F(SimilarityCheckFixture, Test1) {
	sc.setString("AB", "CD");
	result = sc.calcAlphaPoint() + sc.calcCountPoint();
	EXPECT_EQ(60, result);
}

TEST_F(SimilarityCheckFixture, Test2) {
	sc.setString("ASD", "DSA");
	result = sc.calcAlphaPoint() + sc.calcCountPoint();
	EXPECT_EQ(100, result);
}

TEST_F(SimilarityCheckFixture, Test3) {
	sc.setString("A", "BB");
	result = sc.calcAlphaPoint() + sc.calcCountPoint();
	EXPECT_EQ(0, result);
}
#include <string>
#include <iostream>
using namespace std;

class SimilarityChecker {

public:
	int countString(string a, string b) {
		int aLen = a.length();
		int bLen = b.length();
		int result = 0;

		if (aLen == bLen)
			return result = 60;

		if (aLen >= bLen * 2 || aLen * 2 <= bLen)
			return result = 0;

		double coef = getCoefficient(aLen, bLen);		
		return (1 - coef) * 60;
	}

	double getCoefficient(int aLen, int bLen) {
		double gap = abs(aLen - bLen);
		double shorter = aLen < bLen ? aLen : bLen;
		return (gap /shorter);
	}
};
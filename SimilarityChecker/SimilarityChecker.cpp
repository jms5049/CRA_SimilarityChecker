#include <string>
#include <iostream>
using namespace std;

class SimilarityChecker {

public:
	bool equalArrays(int x[], int y[]) {
		for (int i = 0; i < 26; ++i) {
			if (x[i] != y[i])
				return false;
		}
		return true;
	}
	int countAlpha(string a, string b) {
		int aLen = a.length();
		int bLen = b.length();
		int aAlpha[26] = {};
		int bAlpha[26] = {};
		for (int i = 0; i < aLen; i++)
			aAlpha[a[i] - 'A']++;
		for (int i = 0; i < bLen; i++)
			bAlpha[b[i] - 'A']++;

		if (aLen == bLen)
			if (equalArrays(aAlpha, bAlpha))
				return 40;

		return 0;
	}

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
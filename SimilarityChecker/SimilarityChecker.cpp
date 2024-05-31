#include <string>
#include <iostream>
using namespace std;

class SimilarityChecker {
	string originA, originB;
	int aLen, bLen;
	bool lowerCase;

public:
	void setString(string a, string b) {
		originA = a;
		originB = b;
		aLen = a.length();
		bLen = b.length();
		lowerCase = false;
	}

	bool equalArrays(int x[], int y[]) {
		for (int i = 0; i < 26; ++i) {
			if (x[i] != y[i])
				return false;
		}
		return true;
	}

	void countAlphabet(string word, int counter[]) {

		for (int i = 0; i < word.length(); i++) {
			if (word[i] >= 97) {
				lowerCase = true;
				return;
			}
			counter[word[i] - 'A']++;
		}
	}
	double countSubpoint(int aAlphaCounter[], int bAlphaCounter[]) {
		bool alphaFlag[26] = {};
		int totalCount = 0;
		int sameCount = 0;

		for (int i = 0; i < 26; i++) {
			if ((aAlphaCounter[i] || bAlphaCounter[i]) && alphaFlag[i] == 0) {
				totalCount++;
				alphaFlag[i] = 1;
				if ((aAlphaCounter[i] && bAlphaCounter[i]))
					sameCount++;
			}
		}
		if (sameCount == 0)
			return 0;
		return double(totalCount) / double(sameCount);
	}
	int calcAlphaPoint() {
		int aAlphaCounter[26] = {};
		int bAlphaCounter[26] = {};

		countAlphabet(originA, aAlphaCounter);
		countAlphabet(originB, bAlphaCounter);

		if (lowerCase)
			return 0;

		if (aLen == bLen)
			if (equalArrays(aAlphaCounter, bAlphaCounter))
				return 40;

		double subVar = countSubpoint(aAlphaCounter, bAlphaCounter);
		return subVar * 40;
	}

	int calcCountPoint() {

		if (aLen == bLen)
			return 60;

		if (aLen >= bLen * 2 || aLen * 2 <= bLen)
			return 0;

		double coef = getCoefficient(aLen, bLen);
		return (1 - coef) * 60;
	}

	double getCoefficient(int aLen, int bLen) {
		double gap = abs(aLen - bLen);
		double shorter = aLen < bLen ? aLen : bLen;
		return (gap /shorter);
	}
};
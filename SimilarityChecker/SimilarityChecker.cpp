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

	void countAlphabet(string word, int counter[]) {

		for (int i = 0; i < word.length(); i++) {
			if (word[i] >= 97)	return;
				counter[word[i] - 'A']++;
		}
	}

	int countAlpha(string a, string b) {
		int aLen = a.length();
		int bLen = b.length();
		int aAlphaCounter[26] = {};
		int bAlphaCounter[26] = {};
		bool alphabetFlag[26] = {};
		int totalCount = 0;
		int sameCount = 0;

		countAlphabet(a, aAlphaCounter);
		countAlphabet(b, bAlphaCounter);

		if (aLen == bLen)
			if (equalArrays(aAlphaCounter, bAlphaCounter))
				return 40;

		for (int i = 0; i < 26; i++) {
			if ((aAlphaCounter[i] || bAlphaCounter[i]) && alphabetFlag[i] == 0) {
				totalCount++;
				alphabetFlag[i] = 1;
				if ((aAlphaCounter[i] && bAlphaCounter[i]))
					sameCount++;
			}
		}

		return double(sameCount) / double(totalCount) * 40;
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
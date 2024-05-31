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

		int gap = abs(aLen - bLen);
		int shorter = a > b ? aLen : bLen;
		double algo = double(gap) / double(shorter);
		
		return (1 - algo) * 60;
	}
};
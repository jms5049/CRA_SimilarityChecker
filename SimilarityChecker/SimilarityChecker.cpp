#include <string>
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

	}
};
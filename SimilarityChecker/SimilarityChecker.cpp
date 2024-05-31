#include <string>
using namespace std;

class SimilarityChecker {

public:
	int countString(string a, string b) {
		if (a.length() == b.length())
			return 60;
		if (a.length() * 2 == b.length() || b.length() * 2 == a.length())
			return 0;
	}
};
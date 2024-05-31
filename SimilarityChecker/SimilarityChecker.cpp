#include <string>
using namespace std;

class SimilarityChecker {

public:
	int doCheck(string a, string b) {
		if (a.length() == b.length())
			return 60;
	}
};
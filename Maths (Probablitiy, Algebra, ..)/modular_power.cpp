#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
//Modular Power
//n^k mod m

long long power(long long n, long long k, long long m = LLONG_MAX) {
	long long ret = 1;
	while (k) {
		if (k & 1) ret = (ret * n) % m;
		n = (n * n) % m;
		k >>= 1;
	}
	return ret;
}
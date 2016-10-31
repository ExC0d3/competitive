result = kmp::match(text, pattern); // 모든 matched point의 vector
#include <vector>
using namespace std;
namespace kmp
{
typedef vector<int> seq_t;
void calculate_pi(vector<int>& pi, const seq_t& str) {
	pi[0] = -1;
	int j = -1;
	for (int i = 1 ; i < str.size() ; i++) {
		while (j >= 0 && str[i] != str[j + 1]) j = pi[j];
		if (str[i] == str[j + 1])
			pi[i] = ++j;
		else
			pi[i] = -1;
	}
}
/* returns all positions matched */
vector<int> match(seq_t text, seq_t pattern) {
	vector<int> pi(pattern.size());
	vector<int> ans;
	if (pattern.size() == 0) return ans;
	calculate_pi(pi, pattern);
	int j = -1;
	for (int i = 0 ; i < text.size() ; i++) {
		while (j >= 0 && text[i] != pattern[j + 1]) j = pi[j];
		if (text[i] == pattern[j + 1]) {
			j++;
			if (j + 1 == pattern.size()) {
				ans.push_back(i - j);
				j = pi[j];
			}
		}
	}
	return ans;
}
} // namespace kmp
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
// L: doubling method 정렬을 위한 정보
// P[stp][i]: 길이가 1 << stp인 원래 문자열의 위치 i부터 시작하는 버켓 번호
int N, i, stp, cnt;
int A[65536];
struct entry {
	int nr[2], p;
} L[65536];
int P[17][65536];
int suffix_array[65536];
int lcp[65536]; // lcp(i, i + 1)
int cmp(struct entry a, struct entry b) {
	return (a.nr[0] == b.nr[0]) ? (a.nr[1] < b.nr[1]) : (a.nr[0] < b.nr[0]);
}
Seoul National University 25
// calclcp(x, y) = min(lcp[x], lcp[x + 1], ..., lcp[y - 1])
// binary indexed tree needed for speedup
int calclcp(int x, int y) { // x, y: start position in original string
	int k, ret = 0;
	if (x == y) return N - x;
	for (k = stp - 1 ; k >= 0 && x < N && y < N ; k--)
		if (P[k][x] == P[k][y])
			x += 1 << k, y += 1 << k, ret += 1 << k;
	return ret;
}
int main(void) {
	int i;
	scanf("%d", &N);
	for (i = 0 ; i < N ; i++) {
		scanf("%d", &A[i]);
		P[0][i] = A[i];
	}
	for (stp = 1, cnt = 1 ; (cnt >> 1) < N ; stp++, cnt <<= 1) {
		for (i = 0 ; i < N ; i++) {
			L[i].nr[0] = P[stp - 1][i];
			L[i].nr[1] = (i + cnt < N) ? P[stp - 1][i + cnt] : -1;
			L[i].p = i;
		}
		sort(L, L + N, cmp);
		for (i = 0 ; i < N ; i++) {
			P[stp][L[i].p] = (i > 0 && L[i].nr[0] == L[i - 1].nr[0]
			                  && L[i].nr[1] == L[i - 1].nr[1]) ? P[stp][L[i - 1].p] : i;
		}
	}
	for (i = 0 ; i < N ; i++)
		suffix_array[P[stp - 1][i]] = i;
	for (i = 0 ; i + 1 < N ; i++)
		lcp[i] = calclcp(i, i + 1);
	return 0;
}
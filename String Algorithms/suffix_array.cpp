Suffix Array O(n log n)
#include <cstdio>
#include <algorithm>
using namespace std;
int n, K;
int dat[20003];
int ians[20003]; // ans -> index : 답의 반대
int ans[20003]; // index -> ans : 구하고자 하는 suffix array
int tmpans[20003]; // ans의 중간과정 저장
int bucket[20003]; // bucket -> index : starting points
int bucketcnt[20003]; // bucket -> count
int cntbucket; // number of buckets
int bucketmark[20003]; // ans -> bucket : 어느 bucket에 속하는가?
int bucketupdate[20003]; // ans -> bucketnumber. -1이면 새 거.
inline int sf(const int& a, const int& b) {
	return dat[a] < dat[b];
}
int main() {
	int i, H;
	scanf("%d%d", &n, &K);
	for (i = 0 ; i < n ; i++) {
		scanf("%d", &dat[i]);
		dat[i]++;
		ans[i] = i;
		ians[i] = i;
		Seoul National University 24
	}
// constructing suffix array by doubling method
// phase 1: init
	sort(ans, ans + n, sf);
	for (i = 0 ; i < n ; i++) {
		if (i == 0 || dat[ans[i]] != dat[ans[i - 1]]) {
			bucket[cntbucket] = i;
			bucketcnt[cntbucket] = 0;
			cntbucket++;
		}
		bucketmark[ans[i]] = cntbucket - 1;
	}
// phase 2: doubling
	for (H = 1 ; ; H *= 2) {
// phase 2-1: rearrangement
// 현재 위치의 H만큼 뒤를 보면서 위치를 바꿈, 결과를 tmpans에 저장
		for (i = 0 ; i < n ; i++) {
			if (ans[i] >= n - H) {
// 이 뒤는 null 문자이므로 앞으로 가야 한다.
				int tbuck = bucketmark[ans[i]];
				bucketupdate[ans[i]] = -1;
				tmpans[bucket[tbuck] + bucketcnt[tbuck]] = ans[i];
				bucketcnt[tbuck]++;
			}
		}
		for (i = 0 ; i < n ; i++) {
			if (ans[i] >= H) {
// 위에서 처리하지 않은 나머지 것들
				int tbuck = bucketmark[ans[i] - H];
				bucketupdate[ans[i] - H] = bucketmark[ans[i]];
				tmpans[bucket[tbuck] + bucketcnt[tbuck]] = ans[i] - H;
				bucketcnt[tbuck]++;
			}
		}
		/* 만약 정확히 길이가 K인 문자열 중 중복되는 것의 개수를 세려고 한다면,
		* 여기서 처리하라. 그래야 bucketmark가 H인 상태로 남아 있고
		* (bucketmark가 같으면 그 자리에서 H글자만큼의 문자열은 같다는 뜻)
		* 정렬은 2H 길이를 기준으로 되어 있으니까, tmpans를 이용하기.
		* 부분 문자열의 길이 K는 H 이상 2 * H 이하여야 함. */
// phase 2-2: identify new buckets
		int lastbucket = bucketmark[tmpans[0]];
		for (i = 1 ; i < n ; i++) {
			if (bucket[bucketmark[tmpans[i]]] != i) {
				if (bucketupdate[tmpans[i]] != bucketupdate[tmpans[i - 1]]) {
// found new bucket
					bucket[cntbucket] = i;
					lastbucket = cntbucket;
					cntbucket++;
				}
			}
			else {
				lastbucket = bucketmark[tmpans[i]];
			}
			bucketmark[tmpans[i]] = lastbucket;
		}
// phase 2-3: copy ans and calculate ians
		int flg = 0;
		bucketmark[n] = -1;
		for (i = 0 ; i < n ; i++) {
			if (bucketmark[tmpans[i]] == bucketmark[tmpans[i + 1]]) flg = 1;
			ans[i] = tmpans[i];
			ians[ans[i]] = i;
			bucketcnt[bucketmark[ans[i]]] = 0;
		}
		if (flg == 0) break;
	}
	return 0;
}
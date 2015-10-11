long long binomial(int n, int m) {
	if (n > m || n < 0) return 0;
	long long ans = 1, ans2 = 1;
	for (int i = 0 ; i < m ; i++) {
		ans *= n - i;
		ans2 *= i + 1;
	}
	return ans / ans2;
}

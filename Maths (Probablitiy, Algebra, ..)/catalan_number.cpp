long long catalan_number(int n) {
	return binomial(n * 2, n) / (n + 1);
}
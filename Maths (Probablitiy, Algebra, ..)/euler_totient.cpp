phi(n), n 이하의 양수 중 n과 서로 소인 것의 개수를 구한다.
Dependencies: -
// phi(n) = (p_1 - 1) * p_1 ^ (k_1 - 1) * (p_2 - 1) * p_2 ^ (k_2-1)
long long euler_totient2(long long n, long long ps) {
	for (long long i = ps ; i * i <= n ; i++) {
		if (n % i == 0) {
			long long p = 1;
			while (n % i == 0) {
				n /= i;
				p *= i;
			}
			return (p - p / i) * euler_totient2(n, i + 1);
		}
		if (i > 2) i++;
	}
	return n - 1;
}
long long euler_totient(long long n) {
	return euler_totient2(n, 2);
}
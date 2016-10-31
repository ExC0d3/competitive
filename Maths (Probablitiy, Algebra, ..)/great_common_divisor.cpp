long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
//Extended GCD
//ac + bd = gcd(a, b)가 되는 (c, d)를 찾는다.
pair<long long, long long> extended_gcd(long long a, long long b) {
	if (b == 0) return make_pair(1, 0);
	pair<long long, long long> t = extended_gcd(b, a % b);
	return make_pair(t.second, t.first - t.second * (a / b));
}

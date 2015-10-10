//x = a (mod n)가 되는 x를 찾는다.
  //  Dependencies: gcd(a, b), modinverse(a, m)
long long chinese_remainder(long long *a, long long *n, int size) {
	if (size == 1) return *a;
	long long tmp = modinverse(n[0], n[1]);
	long long tmp2 = (tmp * (a[1] - a[0]) % n[1] + n[1]) % n[1];
	long long ora = a[1];
	long long tgcd = gcd(n[0], n[1]);
	a[1] = a[0] + n[0] / tgcd * tmp2;
	n[1] *= n[0] / tgcd;
	long long ret = chinese_remainder(a + 1, n + 1, size - 1);
	n[1] /= n[0] / tgcd;
	a[1] = ora;
	return ret;
}

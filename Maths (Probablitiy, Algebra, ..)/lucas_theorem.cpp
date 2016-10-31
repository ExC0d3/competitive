//nCm mod p의 값을 구한다.
//Dependencies: binomial(n, m)
int lucas_theorem(const char *n, const char *m, int p) {
	vector<int> np, mp;
	int i;
	for (i = 0 ; n[i] ; i++) {
		if (n[i] == '0' && np.empty()) continue;
		np.push_back(n[i] - '0');
	}
	for (i = 0 ; m[i] ; i++) {
		if (m[i] == '0' && mp.empty()) continue;
		mp.push_back(m[i] - '0');
		Seoul National University 13
	}
	int ret = 1;
	int ni = 0, mi = 0;
	while (ni < np.size() || mi < mp.size()) {
		int nmod = 0, mmod = 0;
		for (i = ni ; i < np.size() ; i++) {
			if (i + 1 < np.size())
				np[i + 1] += (np[i] % p) * 10;
			else
				nmod = np[i] % p;
			np[i] /= p;
		}
		for (i = mi ; i < mp.size() ; i++) {
			if (i + 1 < mp.size())
				mp[i + 1] += (mp[i] % p) * 10;
			else
				mmod = mp[i] % p;
			mp[i] /= p;
		}
		while (ni < np.size() && np[ni] == 0) ni++;
		while (mi < mp.size() && mp[mi] == 0) mi++;
		ret = (ret * binomial(nmod, mmod)) % p;
	}
	return ret;
}
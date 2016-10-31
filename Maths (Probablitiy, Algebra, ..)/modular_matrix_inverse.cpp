//Dependencies: modinverse(a, m)
// returns empty vector if fails
vector<vector<long long> > mat_inverse(vector<vector<long long> > matrix, int n,
                                       long long mod) {
	int i, j, k;
	vector<vector<long long> > ret;
	ret.resize(n);
	for (i = 0 ; i < n ; i++) {
		ret[i].resize(n);
		for (j = 0 ; j < n ; j++)
			ret[i][j] = 0;
		ret[i][i] = 1 % mod;
	}
	for (i = 0 ; i < n ; i++) {
		if (matrix[i][i] == 0) {
			for (j = i + 1 ; j < n ; j++) {
				if (matrix[j][i] != 0) {
					for (k = 0 ; k < n ; k++) {
						matrix[i][k] = (matrix[i][k] + matrix[j][k]) % mod;
						ret[i][k] = (ret[i][k] + ret[j][k]) % mod;
					}
					break;
				}
			}
			if (j == n) {
				ret.clear();
				return ret;
			}
		}
		long long tmp = modinverse(matrix[i][i], mod);
		for (k = 0 ; k < n ; k++) {
			matrix[i][k] = (matrix[i][k] * tmp) % mod;
			ret[i][k] = (ret[i][k] * tmp) % mod;
		}
		for (j = 0 ; j < n ; j++) {
			if (j == i) continue;
			tmp = matrix[j][i];
			for (k = 0 ; k < n ; k++) {
				matrix[j][k] -= matrix[i][k] * tmp;
				matrix[j][k] = (matrix[j][k] % mod + mod) % mod;
				ret[j][k] -= ret[i][k] * tmp;
				ret[j][k] = (ret[j][k] % mod + mod) % mod;
			}
		}
	}
	return ret;
}
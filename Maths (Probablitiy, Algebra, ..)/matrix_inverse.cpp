Dependencies: -
inline bool eq(double a, double b) {
	static const double eps = 1e-9;
	return fabs(a - b) < eps;
}
// returns empty vector if fails
vector<vector<double> > mat_inverse(vector<vector<double> > matrix, int n) {
	int i, j, k;
	vector<vector<double> > ret;
	ret.resize(n);
	for (i = 0 ; i < n ; i++) {
		ret[i].resize(n);
		for (j = 0 ; j < n ; j++)
			ret[i][j] = 0;
		ret[i][i] = 1;
	}
	for (i = 0 ; i < n ; i++) {
		if (eq(matrix[i][i], 0)) {
			for (j = i + 1 ; j < n ; j++) {
				if (!eq(matrix[j][i], 0)) {
					for (k = 0 ; k < n ; k++) {
						matrix[i][k] += matrix[j][k];
						ret[i][k] += ret[j][k];
					}
					break;
				}
			}
			if (j == n) {
				ret.clear();
				return ret;
				Seoul National University 14
			}
		}
		double tmp = matrix[i][i];
		for (k = 0 ; k < n ; k++) {
			matrix[i][k] /= tmp;
			ret[i][k] /= tmp;
		}
		for (j = 0 ; j < n ; j++) {
			if (j == i) continue;
			tmp = matrix[j][i];
			for (k = 0 ; k < n ; k++) {
				matrix[j][k] -= matrix[i][k] * tmp;
				ret[j][k] -= ret[i][k] * tmp;
			}
		}
	}
	return ret;
}
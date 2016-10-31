//Dependencies: -
double mat_det(vector<vector<double> > matrix, int n) {
	int i, j, k;
	double ret = 1;
	for (i = 0 ; i < n ; i++) {
		if (eq(matrix[i][i], 0)) {
			for (j = i + 1 ; j < n ; j++) {
				if (!eq(matrix[j][i], 0)) {
					for (k = 0 ; k < n ; k++)
						matrix[i][k] += matrix[j][k];
					break;
				}
			}
			if (j == n)
				return 0;
		}
		double tmp = matrix[i][i];
		for (k = 0 ; k < n ; k++)
			matrix[i][k] /= tmp;
		Seoul National University 15
		ret *= tmp;
		for (j = 0 ; j < n ; j++) {
			if (j == i) continue;
			tmp = matrix[j][i];
			for (k = 0 ; k < n ; k++)
				matrix[j][k] -= matrix[i][k] * tmp;
		}
	}
	return ret;
}
//Dependencies: mat_det(matrix, n)
long long count_spantree(vector<int> graph[], int size) {
	int i, j;
	vector<vector<double> > matrix(size - 1);
	for (i = 0 ; i < size - 1 ; i++) {
		matrix[i].resize(size - 1);
		for (j = 0 ; j < size - 1 ; j++)
			matrix[i][j] = 0;
		for (j = 0 ; j < graph[i].size() ; j++) {
			if (graph[i][j] < size - 1) {
				matrix[i][graph[i][j]]--;
				matrix[i][i]++;
			}
		}
	}
	return (long long)(mat_det(matrix, size - 1) + 0.5);
}
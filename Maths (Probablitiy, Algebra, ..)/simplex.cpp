Simplex Algorithm
n : = number of constraints
      m : = number of variables
            matrix[0] : = maximize할 식의 계수
                          matrix[1~n] : = constraints
                                  solution : = results
                                          solution[n] : = 원하는 식의 최대값
                                                  부등식의 우변(변수 없는 쪽)이 음이 아닌 수가 되도록 정리하여 대입한다.
                                                  ex) Maximize p = -2x + 3y
                                                          Constraints: x + 3y ≤ 40
                                                          2x + 4y ≥ 10
                                                          x ≥ 0, y ≥ 0
                                                          n = 2, m = 2, matrix = [ 2 - 3 1 0 0 ] , c = [ 0 ]
                                                                  [ 1 3 0 1 0 ] [ 40 ]
                                                                  [ 2 4 0 0 - 1 ] [ 10 ]
                                                                  namespace simplex
{
const int MAX_N = 50;
const int MAX_M = 50;
const double eps = 1e-9;
inline int diff(double a, double b) {
	if (a - eps < b && b < a + eps) return 0;
	return (a < b) ? -1 : 1;
}
int n, m;
double matrix[MAX_N + 1][MAX_M + MAX_N + 1];
double c[MAX_N + 1];
double solution[MAX_M + MAX_N + 1];
int simplex() { // 0: found solution, 1: no feasible solution, 2: unbounded
	int i, j;
	while (true) {
		int nonfeasible = -1;
		for (j = 0 ; j <= n + m ; j++) {
			Seoul National University 17
			int cnt = 0, pos = -1;
			for (i = 0 ; i <= n ; i++) {
				if (diff(matrix[i][j], 0)) {
					cnt++;
					pos = i;
				}
			}
			if (cnt != 1)
				solution[j] = 0;
			else {
				solution[j] = c[pos] / matrix[pos][j];
				if (solution[j] < 0) nonfeasible = i;
			}
		}
		int pivotcol = -1;
		if (nonfeasible != -1) {
			double maxv = 0;
			for (j = 0 ; j <= n + m ; j++) {
				if (maxv < matrix[nonfeasible][j]) {
					maxv = matrix[nonfeasible][j];
					pivotcol = j;
				}
			}
			if (pivotcol == -1) return 1;
		}
		else {
			double minv = 0;
			for (j = 0 ; j <= n + m ; j++) {
				if (minv > matrix[0][j]) {
					minv = matrix[0][j];
					pivotcol = j;
				}
			}
			if (pivotcol == -1) return 0;
		}
		double minv = -1;
		int pivotrow = -1;
		for (i = 0 ; i <= n ; i++) {
			if (diff(matrix[i][pivotcol], 0) > 0) {
				double test = c[i] / matrix[i][pivotcol];
				if (test < minv || minv < 0) {
					minv = test;
					pivotrow = i;
				}
			}
		}
		if (pivotrow == -1) return 2;
		for (i = 0 ; i <= n ; i++) {
			if (i == pivotrow) continue;
			if (diff(matrix[i][pivotcol], 0)) {
				double ratio = matrix[i][pivotcol] / matrix[pivotrow][pivotcol];
				for (j = 0 ; j <= n + m ; j++) {
					if (j == pivotcol) {
						matrix[i][j] = 0;
						continue;
					}
					else
						matrix[i][j] -= ratio * matrix[pivotrow][j];
				}
				c[i] -= ratio * c[pivotrow];
			}
		}
	}
}
} // namespace simplex
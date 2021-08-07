// https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
public:

	int n, m;
	vector<vector<int>> prefix_sum;

	NumMatrix(vector<vector<int>>& matrix) {
		n = matrix.size();
		m = matrix[0].size();
		prefix_sum = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				prefix_sum[i][j] = prefix_sum[i][j - 1] + prefix_sum[i - 1][j] - prefix_sum[i - 1][j - 1] + matrix[i - 1][j - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return prefix_sum[row2 + 1][col2 + 1] - prefix_sum[row1][col2 + 1] - prefix_sum[row2 + 1][col1] + prefix_sum[row1][col1];
	}
};
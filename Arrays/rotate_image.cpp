// https://leetcode.com/problems/rotate-image/

// Inplace rotation - Idea is to transpose the matrix and then reverse each row.
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        for (int k = 0; k < n - 1; k++) {
            int i = k, j = k;
            while (i < n - 1 && j < n - 1) {
                int temp = matrix[k][j + 1];
                matrix[k][j + 1] = matrix[i + 1][k];
                matrix[i + 1][k] = temp;
                i++;
                j++;
            }
        }

        for (int i = 0; i < n; i++) {
            int start = 0, end = n - 1;
            while (start < end) {
                int temp = matrix[i][start];
                matrix[i][start] = matrix[i][end];
                matrix[i][end] = temp;
                start++;
                end--;
            }
        }
    }
};


/* BRUTE-FORCE 0(N) Space

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int new_matrix[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                new_matrix[j][n - i - 1] = matrix[i][j];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                matrix[i][j] = new_matrix[i][j];
        }
    }
};
*/
// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

class Solution {
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {

		int ans = 0, flag = 0;
		int i = 0, j = m - 1;
		while (i < n && j >= 0) {
			if (arr[i][j] == 1) {
				ans = i;
				flag = 1;
				j--;
			} else {
				i++;
			}
		}

		if (!flag) return -1;
		else return ans;
	}
};
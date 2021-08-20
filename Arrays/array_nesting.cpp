// https://leetcode.com/problems/array-nesting/

class Solution {
public:
	int arrayNesting(vector<int>& nums) {
		int n = nums.size();
		int maxCount = 1;
		for (int i = 0; i < n; i++) {
			int count = 1;
			if (nums[i] >= 0) {
				int idx = nums[i];
				while (i != idx) {
					int temp = nums[idx];
					nums[idx] = -(1 + nums[idx]);
					idx = temp;
					count++;
				}
				nums[idx] = -(1 + nums[idx]);
			}

			maxCount = max(maxCount, count);
		}

		return maxCount;
	}
};
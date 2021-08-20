// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {

		int n1 = 0, n2 = 1, c1 = 0, c2 = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == n1)
				c1++;
			else if (nums[i] == n2)
				c2++;
			else if (c1 == 0) {
				n1 = nums[i];
				c1 = 1;
			} else if (c2 == 0) {
				n2 = nums[i];
				c2 = 1;
			} else {
				c1--;
				c2--;
			}
		}

		vector<int> majorities;
		if (count(nums.begin(), nums.end(), n1) > nums.size() / 3)
			majorities.push_back(n1);

		if (count(nums.begin(), nums.end(), n2) > nums.size() / 3)
			majorities.push_back(n2);

		return majorities;
	}
};
// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		int suffix_prod[n];
		suffix_prod[n - 1] = nums[n - 1];

		for (int i = n - 2; i >= 0; i--)
			suffix_prod[i] = nums[i] * suffix_prod[i + 1];

		vector<int> v;
		v.push_back(suffix_prod[1]);
		int prod = nums[0];
		for (int i = 1; i < n - 1; i++) {
			v.push_back(prod * suffix_prod[i + 1]);
			prod = prod * nums[i];
		}

		v.push_back(prod);
		return v;
	}
};
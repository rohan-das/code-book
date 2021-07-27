// https://leetcode.com/problems/rotate-array/

// Reverse vector approach.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};


/* Uses Modulo operation and extra O(N) space.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> v(n);
        for (int i = 0; i < n; i++)
            v[(i + k) % n] = nums[i];

        nums = v;
    }
};
*/
// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        if (n == 0) return 0;

        int SMAX[n];
        SMAX[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--)
            SMAX[i] = max(SMAX[i + 1], height[i]);

        int PMAX = INT_MIN, res = 0;
        for (int i = 1; i < n - 1; i++) {
            PMAX = max(PMAX, height[i - 1]);
            if (height[i] < PMAX && height[i] < SMAX[i + 1])
                res = res + min(PMAX, SMAX[i + 1]) - height[i];
        }

        return res;
    }
};
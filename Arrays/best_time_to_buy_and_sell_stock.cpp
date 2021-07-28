// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int res = 0, n = prices.size();
        int PMIN = prices[0];

        for (int i = 1; i < n; i++) {
            res = max(res, prices[i] - PMIN);
            PMIN = min(PMIN, prices[i]);
        }

        return res;
    }
};
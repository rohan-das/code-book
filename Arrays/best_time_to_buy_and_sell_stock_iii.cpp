// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int n = prices.size();
		if (n == 1) return 0;

		int prefix_min[n], prefix_profit[n];

		prefix_min[0] = prices[0];
		for (int i = 1; i < n; i++)
			prefix_min[i] = min(prefix_min[i - 1], prices[i]);

		prefix_profit[0] = 0;
		for (int i = 1; i < n; i++)
			prefix_profit[i] = max(prefix_profit[i - 1], prices[i] - prefix_min[i - 1]);

		int suffix_max[n], suffix_profit[n];

		suffix_max[n - 1] = prices[n - 1];
		for (int i = n - 2; i >= 0; i--)
			suffix_max[i] = max(suffix_max[i + 1], prices[i]);

		suffix_profit[n - 1] = 0;
		for (int i = n - 2; i >= 0; i--)
			suffix_profit[i] = max(suffix_profit[i + 1], suffix_max[i + 1] - prices[i]);

		int profit = prefix_profit[n - 1];

		for (int i = 1; i < n; i++)
			profit = max(profit, prefix_profit[i - 1] + suffix_profit[i]);

		return profit;
	}
};
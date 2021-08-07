// https://practice.geeksforgeeks.org/problems/sum-of-subarrays2229/1

const unsigned int M = 1e9 + 7;

class Solution {
public:
	long long subarraySum(long long a[], long long n)
	{
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			sum = ((sum % M) + ((((a[i] % M * (i + 1) % M) % M) % M * (n - i) % M) % M) % M) % M;
		}

		return sum;
	}
};
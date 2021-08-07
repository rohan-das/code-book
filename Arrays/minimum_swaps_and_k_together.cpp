// https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

int minSwap(int *arr, int n, int k) {

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] <= k)
			count++;
	}

	int cnt = 0;
	for (int i = 0; i < count; i++) {
		if (arr[i] <= k)
			cnt++;
	}

	int maxCount = cnt;
	for (int i = count; i < n; i++) {
		if (arr[i - count] <= k)
			cnt--;
		if (arr[i] <= k)
			cnt++;
		maxCount = max(maxCount, cnt);
	}

	return count - maxCount;
}

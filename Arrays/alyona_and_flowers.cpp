// https://codeforces.com/problemset/problem/740/B

#include <bits/stdc++.h>
using namespace std;

int32_t main() {

	int n, m;
	cin >> n >> m;

	int a[n + 1], PSUM[n + 1];
	PSUM[0] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		PSUM[i] = PSUM[i - 1] + a[i];
	}

	int x, y, res = 0;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		res = max(res, res + PSUM[y] - PSUM[x - 1]);
	}

	cout << res << "\n";

	return 0;
}
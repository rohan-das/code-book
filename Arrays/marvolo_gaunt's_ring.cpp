// https://codeforces.com/problemset/problem/855/B

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n, p, q, r;
    cin >> n >> p >> q >> r;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll SMAX[n];
    SMAX[n - 1] = r * a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        SMAX[i] = max(SMAX[i + 1], r * a[i]);

    ll PMAX = LLONG_MIN, res = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        PMAX = max(PMAX, p * a[i]);
        res = max(res, PMAX + (q * a[i]) + SMAX[i]);
    }

    cout << res << "\n";
}

// Problem: D. Dasha and Very Difficult Problem
// Contest: Codeforces - Codeforces Round #394 (Div. 2)
// URL: https://codeforces.com/contest/761/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	int a[n + 7], c[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	int b[n + 7];
	int mn = MOD, mx = -1;
	for (int i = 0; i < n; i++) {
		b[i] = a[i] + c[i];
		mn = min(b[i], mn);
		mx = max(b[i], mx);
	}
	if (mx - mn > r - l) {cout << -1 << endl;}
	else {
		for (int i = 0; i < n; i++) {
			cout << b[i] - (mx - r) << " ";
		}
		cout << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
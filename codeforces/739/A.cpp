
// Problem: A. Alyona and mex
// Contest: Codeforces - Codeforces Round #381 (Div. 1)
// URL: https://codeforces.com/problemset/problem/739/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	int l, r, mn = MOD;
	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		mn = min(mn, r - l + 1);
	}
	cout << mn << endl;
	for (int i = 0; i < n; i++) {
		cout << (i % mn) << ' ';
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
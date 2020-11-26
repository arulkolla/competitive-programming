
// Problem: D1. Coffee and Coursework (Easy version)
// Contest: Codeforces - Codeforces Round #540 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1118/D1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, p;
	cin >> n >> p;
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, greater<int>());
	for (int day = 1; day <= n; day++) {
		int tot = 0;
		for (int i = 0; i < n; i++) {
			tot += max(0, a[i] - i / day);
		}
		if (tot >= p) {cout << day; return;}
	}
	cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
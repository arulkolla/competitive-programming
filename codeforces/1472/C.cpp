
// Problem: C. Long Jumps
// Contest: Codeforces - Codeforces Round #693 (Div. 3)
// URL: https://codeforces.com/contest/1472/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7], dp[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = 0;
	}
	for (int i = n; i >= 1; i--) {
		if (i + a[i] > n) {dp[i] = a[i];}
		else {dp[i] = dp[i + a[i]] + a[i];}
	}
	int mx = -1;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, dp[i]);
	}
	cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
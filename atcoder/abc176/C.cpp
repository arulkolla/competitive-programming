
// Problem: C - Step
// Contest: AtCoder - AtCoder Beginner Contest 176
// URL: https://atcoder.jp/contests/abc176/tasks/abc176_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long mx = a[0];
	long long res = 0;
	for (int i = 1; i < n; i++) {
		if (mx >= a[i]) {
			res += mx - a[i];
		}
		else {
			mx = a[i];
		}
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
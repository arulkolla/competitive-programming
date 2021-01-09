
// Problem: B - Smartphone Addiction
// Contest: AtCoder - AtCoder Beginner Contest 185
// URL: https://atcoder.jp/contests/abc185/tasks/abc185_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n, t;
	int m;
	cin >> n >> m >> t;
	long long curr = n, prev = 0;
	for (int i = 0; i < m; i++) {
		long long a, b;
		cin >> a >> b;
		curr -= a - prev;
		if (curr <= 0) {cout << "No"; return;}
		curr += b - a;
		curr = min(curr, n);
		prev = b;
	}
	curr -= t - prev;
	if (curr <= 0) {cout << "No"; return;}
	cout << "Yes";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
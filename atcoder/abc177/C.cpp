
// Problem: C - Sum of product of pairs
// Contest: AtCoder - AtCoder Beginner Contest 177
// URL: https://atcoder.jp/contests/abc177/tasks/abc177_c
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
	long long sum = 0, square = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		long long now = (a[i] * a[i]) % MOD;
		square += now;
		sum %= MOD;
		square %= MOD;
	}
	sum = (sum * sum) % MOD;
	cout << (((sum - square + MOD) % MOD) * 500000004) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
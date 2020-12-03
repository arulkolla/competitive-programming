
// Problem: C - Digits in Multiplication
// Contest: AtCoder - AtCoder Beginner Contest 057
// URL: https://atcoder.jp/contests/abc057/tasks/abc057_c
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n;
	cin >> n;
	long long mx = -1;
	for (long long i = 1; i * i <= n; i++) {
		if (n % i == 0) {mx = max(mx, i);}
	}
	long long mx2 = n / mx;
	cout << max(to_string(mx).size(), to_string(mx2).size());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
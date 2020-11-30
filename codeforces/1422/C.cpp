
// Problem: C. Bargain
// Contest: Codeforces - Codeforces Round #675 (Div. 2)
// URL: https://codeforces.com/contest/1422/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	string s;
	cin >> s;
	long long res = 0, curr = 0, p = 1, n = s.length();
	for (long long i = n - 1; i >= 0; i--) {
		long long rn = (((i * (i + 1) / 2) % MOD) * p % MOD + curr) % MOD;
		curr = curr + (p * (n - i) % MOD);
		curr %= MOD;
		p = (p * 10) % MOD;
		res = res + (rn * (s[i] - '0') % MOD);
		res %= MOD;
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
// Problem: C. Problem for Nazar
// Contest: Codeforces - Codeforces Round #553 (Div. 2)
// URL: https://codeforces.com/contest/1151/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long res(long long n) {
	long long pow = 1, cnt = 1, odd = 0, even = 0;
	while (n > 0) {
		long long val = min(pow, n);
		n -= val;
		if (cnt % 2) {
			odd += val;
			odd %= MOD;
		}
		else {
			even += val;
			even %= MOD;
		}
		pow *= 2;
		cnt++;
	}
	odd = odd * odd;
	odd %= MOD; 
	even = even * even + even;
	even %= MOD;
	return odd + even;
}

void solve() {
	long long l, r;
	cin >> l >> r;
	long long ans = res(r) - res(l - 1);
	while (ans < MOD) {
		ans += MOD;
	}
	cout << ans % MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
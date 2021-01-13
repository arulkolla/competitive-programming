
// Problem: C. Quiz
// Contest: Codeforces - Codeforces Round #196 (Div. 2)
// URL: https://codeforces.com/contest/337/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000009;

long long add(long long x, long long y) {
	x %= MOD;
	y %= MOD;
	return (x + y) % MOD;
}
 
long long sub(long long x, long long y) {
	while (y < 0) {y += MOD;}
	x %= MOD;
	y %= MOD;
	return add(x, MOD - y);
}
 
long long mul(long long x, long long y) {
	x %= MOD;
	y %= MOD;
	return (x * 1ll * y) % MOD;
}

long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
	long long n, m, k;
	cin >> n >> m >> k;
	long long left = (n / k * (k - 1)) + (n % k);
	if (m <= left) {cout << m; return;}
	long long filled = m - left, rem = m - (filled * k);
	long long res = binpow(2, filled + 1);
	res = sub(res, 2ll);
	res = mul(res, k);
	res = add(res, rem);
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
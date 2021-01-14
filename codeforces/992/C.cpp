
// Problem: C. Nastya and a Wardrobe
// Contest: Codeforces - Codeforces Round #489 (Div. 2)
// URL: https://codeforces.com/problemset/problem/992/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

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
	long long x, k;
	cin >> x >> k;
	if (x == 0) {cout << 0; return;}
	long long res = 1, v = binpow(2, k), odd = sub(mul(x, 2), 1);
	v = mul(v, odd);
	res = add(res, v);
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
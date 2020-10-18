
// Problem: D. Iterated Linear Function
// Contest: Codeforces - Educational Codeforces Round 13
// URL: https://codeforces.com/problemset/problem/678/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
	long long a, b, x, n;
	cin >> a >> b >> n >> x;
	if (a == 1) {
		cout << (x + n % MOD * b) % MOD;
		return;
	}
	long long apown = binpow(a, n, MOD) * x % MOD;
	apown += (binpow(a, n, MOD) - 1) * binpow(a - 1, MOD - 2, MOD) % MOD * b;
	cout << (apown % MOD + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
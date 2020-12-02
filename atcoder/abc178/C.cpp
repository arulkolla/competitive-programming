
// Problem: C - Ubiquity
// Contest: AtCoder - AtCoder Beginner Contest 178
// URL: https://atcoder.jp/contests/abc178/tasks/abc178_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

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
	long long b;
	cin >> b;
	long long res = (((binpow(10ll, b) + binpow(8ll, b)) % MOD) - 2 * binpow(9ll, b));
	while (res < MOD) {res += MOD;}
	res %= MOD;
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
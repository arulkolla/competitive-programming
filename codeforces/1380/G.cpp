
// Problem: G. Circular Dungeon
// Contest: Codeforces - Educational Codeforces Round 91 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1380/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 300007;
const int MOD = 998244353;

long long binpow(long long a, long long b, int m) {
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

long long pref[MAX];

long long query(int l, int r, int m) {
	l = max(l, 1);
	return (pref[r] - pref[l - 1] + m) % m;
}

void solve() {
	int n;
	cin >> n;
	long long c[MAX];
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	sort(c + 1, c + n + 1);
	pref[0] = 0;
	for (int i = 1; i <= n; i++) {
		pref[i] = (pref[i - 1] + c[i]) % MOD;
	}
	for (int i = 1; i <= n; i++) {
		int s = n - i, g = 1;
		long long res = 0;
		while (s > 0) {
			res += query(s - i + 1, s, MOD) * g % MOD;
			res %= MOD;
			s -= i;
			g++;
		}
		cout << res * binpow(n, MOD - 2, MOD) % MOD << " ";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
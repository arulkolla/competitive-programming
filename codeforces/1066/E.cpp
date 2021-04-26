#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const long long MOD = 998244353;

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
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s;
	cin >> t;
	long long pref[m + 7];
	for (int i = 0; i < m + 5; i++) {
		pref[i] = 0;
	}
	pref[0] = 1ll;
	for (int i = 1; i < m; i++) {
		if (t[i] == '1') {
			pref[i]++;
		}
		pref[i] += pref[i - 1];
	}
	// for (int i = 0; i < m; i++) {
		// cout << pref[i] << ' ';
	// } cout << endl;
	long long res = 0, now;
	int pos = max(m - n, 0);
	for (int i = 0; i < n; i++) {
		if (i < n - m) {continue;}
		if (s[i] == '1') {
			 // cout << i << ' ' << pos << endl;
			now = binpow(2ll, n - 1 - i, MOD);
			now *= pref[pos];
			now %= MOD;
			res += now;
			res %= MOD;
		}
		pos++;
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
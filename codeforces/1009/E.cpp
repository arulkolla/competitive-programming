#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	long long a[n + 7];
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
		a[i] %= MOD;
	}
	long long res = 0, pow2 = 1;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			res += a[n];
			res %= MOD;
		}
		else if (i == 2) {
			res += (2ll * a[n - 1]) % MOD;
			res %= MOD;
		}
		else {
			res += (((pow2 * (i + 2)) % MOD) * a[n - i + 1]) % MOD;
			res %= MOD;
			pow2 *= 2;
			pow2 %= MOD;
		}
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
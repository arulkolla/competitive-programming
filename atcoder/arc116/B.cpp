#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	long long a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long res = 0, val = 0, pow = 1;
	for (int i = 1; i < n; i++) {
		val = (val + (a[i] * pow) % MOD) % MOD;
		pow = (pow * 2) % MOD;
	}
	for (int i = 0; i < n; i++) {
		res = (res + (a[i] * val) % MOD) % MOD;
		if (i < n - 1) {
			val -= a[i + 1];
			while (val <= 0) {val += MOD;}
			val %= MOD;
			val = (val * 499122177ll) % MOD;
		}
	}
	for (int i = 0; i < n; i++) {
		res = (res + (a[i] * a[i]) % MOD) % MOD;
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
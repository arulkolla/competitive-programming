#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long x;
	cin >> n >> x;
	long long a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (a[i] > x) {n = i; break;}
	}
	long long pref[n + 7];
	pref[0] = a[0];
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + a[i];
		if (pref[i] > x) {n = i; break;}
	}
	long long val[n + 7];
	for (int i = 0; i < n; i++) {
		// cout << "m: " << i + 1 << "  b: " << (pref[i] - (i + 1)) << '\n';
		val[i] = (x - (pref[i] - (i + 1))) / (i + 1);
	}
	reverse(val, val + n);
	// for (int i = 0; i < n; i++) {cout << val[i] << ' ';} cout << '\n';
	for (int i = n - 1; i >= 1; i--) {
		val[i] = val[i] - val[i - 1];
	}
	// for (int i = 0; i < n; i++) {cout << val[i] << ' ';} cout << '\n';
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += (val[i]) * (long long)(n - i);
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
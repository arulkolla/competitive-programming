#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, x;
	cin >> n >> x;
	long long mn = MOD, mx = -MOD;
	long long res = 0;
	long long a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0) {res += abs(a[i] - a[i - 1]);}
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	long long small = 1LL, large = (long long)x;
	if (small >= mn) {small = MOD;}
	if (large <= mx) {large = MOD;}
	if (small != MOD) {
		long long rsmall = min(abs(a[0] - small), abs(a[n - 1] - small));
		for (int i = 0; i < n - 1; i++) {
			rsmall = min(rsmall, 2 * abs(min(a[i], a[i + 1]) - small));
		}
		res += rsmall;
	}
	if (large != MOD) {
		long long rlarge = min(abs(a[0] - large), abs(a[n - 1] - large));
		for (int i = 0; i < n - 1; i++) {
			rlarge = min(rlarge, 2 * abs(max(a[i], a[i + 1]) - large));
		}
		res += rlarge;
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
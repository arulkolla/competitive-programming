#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long a, b;
	cin >> n >> a >> b;
	long long x[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	x[0] = 0LL;
	long long xa[n + 7], xb[n + 7], xbp[n + 7];
	for (int i = 1; i <= n; i++) {
		xa[i] = (x[i] - x[i - 1]) * a;
		xb[i] = (x[i] - x[i - 1]) * b;
		xbp[i] = xb[i] * (long long)(n - i + 1);
	}
	xa[0] = xb[0] = xbp[0] = 0LL;
	// for (int i = 0; i <= n; i++) {
		// cout << xa[i] << ' ';
	// }
	// cout << '\n';
	// for (int i = 0; i <= n; i++) {
		// cout << xb[i] << ' ';
	// }
	// cout << '\n';
	// for (int i = 0; i <= n; i++) {
		// cout << xbp[i] << ' ';
	// }
	// cout << '\n';
	// cout << '\n';
	
	long long xn[n + 7];
	for (int i = 0; i <= n; i++) {
		xn[i] = xa[i] + xb[i];
	}
	long long xpsum[n + 7], xppsum[n + 7];
	xpsum[0] = 0LL; xppsum[0] = 0LL;
	for (int i = 1; i <= n; i++) {
		xpsum[i] = xn[i] + xpsum[i - 1];
		xppsum[i] = xbp[i] + xppsum[i - 1];
	}
	// for (int i = 0; i <= n; i++) {
		// cout << xpsum[i] << ' ';
	// }
	// cout << '\n';
	// for (int i = 0; i <= n; i++) {
		// cout << xppsum[i] << ' ';
	// }
	// cout << '\n';
	// cout << '\n';
	
	long long res = 1'000'000'000'000'000LL;
	for (int i = 0; i <= n; i++) {
		res = min(res, xpsum[i] + xppsum[n] - xppsum[i]);
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
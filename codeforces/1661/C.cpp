#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long f(long long ocnt, long long tcnt, long long k) {
	return max(2 * (tcnt - k), 2 * (ocnt + 2 * k) - 1);
}

void solve() {
	int n;
	cin >> n;
	long long h[n + 7], mx = -1;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		mx = max(mx, h[i]);
	}
	long long a[n + 7], b[n + 7], res = MOD;
	for (int i = 0; i < n; i++) {
		a[i] = mx - h[i];
		b[i] = a[i] + 1;
	}
	long long ocnt = 0, tcnt = 0;
	for (int i = 0; i < n; i++) {
		ocnt += a[i] % 2;
		tcnt += a[i] / 2;
	}
	long long k1 = (2 * (tcnt - ocnt) + 1) / 6, k2 = k1 + 1;
	k1 = max(k1, 0LL); k2 = max(k2, 0LL);
	long long res1 = f(ocnt, tcnt, k1), res2 = f(ocnt, tcnt, k2);
	res = min(res1, res2);
	
	ocnt = 0, tcnt = 0;
	for (int i = 0; i < n; i++) {
		ocnt += b[i] % 2;
		tcnt += b[i] / 2;
	}
	k1 = (2 * (tcnt - ocnt) + 1) / 6, k2 = k1 + 1;
	res1 = f(ocnt, tcnt, k1), res2 = f(ocnt, tcnt, k2);
	k1 = max(k1, 0LL); k2 = max(k2, 0LL);
	res = min(res, min(res1, res2));
	
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
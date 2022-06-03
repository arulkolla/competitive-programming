#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long k;
	cin >> n >> k;
	long long a[n + 7], pref[n + 7], sum = 0;
	pref[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	if (k >= n) {
		cout << sum + ((long long)(2 * k - n - 1) * (long long)(n)) / 2 << '\n';
	}
	else {
		long long mx = -MOD;
		for (int i = k; i <= n; i++) {
			mx = max(mx, pref[i] - pref[i - k]);
		}
		cout << mx + ((k - 1) * (k)) / 2 << '\n';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
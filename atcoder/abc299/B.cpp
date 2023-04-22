#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, t;
	cin >> n >> t;
	int a[n + 7], b[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	int mx = -1, mxi = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == t) {
			if (mx < b[i]) {
				mx = b[i];
				mxi = i;
			}
		}
	}
	if (mx != -1) {
		cout << mxi << '\n';
		return;
	}
	t = a[1];
	for (int i = 1; i <= n; i++) {
		if (a[i] == t) {
			if (mx < b[i]) {
				mx = b[i];
				mxi = i;
			}
		}
	}
	cout << mxi << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	solve();
}
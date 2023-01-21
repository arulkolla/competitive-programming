#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (m == 1) {cout << 0 << '\n'; return;}
	sort(a, a + n);
	set<int> r, l;
	int mn = -1, mx = -1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 1; j * j <= a[i]; j++) {
			if (a[i] % j == 0 && j <= m) {
				r.insert(j);
				if (a[i] / j <= m) {r.insert(a[i] / j);}
			}
		}
		if (r.size() >= m) {mn = i; break;}
	}
	if (mn == -1) {cout << mn << '\n'; return;}
	for (int i = mn; i < n; i++) {
		for (int j = 1; j * j <= a[i]; j++) {
			if (a[i] % j == 0 && j <= m) {
				l.insert(j);
				if (a[i] / j <= m) {l.insert(a[i] / j);}
			}
		}
		if (l.size() >= m) {mx = i; break;}
	}
	int res = a[mx] - a[mn];
	while (mn > 0) {
		// cout << "testing " << mx << '\n';
		mx--;
		r.clear(); l.clear();
		for (int i = mx; i >= 0; i--) {
			for (int j = 1; j * j <= a[i]; j++) {
				if (a[i] % j == 0 && j <= m) {
					r.insert(j);
					if (a[i] / j <= m) {r.insert(a[i] / j);}
				}
			}
			if (r.size() >= m) {mn = i; break;}
		}
		if (r.size() < m) {break;}
		for (int i = mn; i <= mx; i++) {
			for (int j = 1; j * j <= a[i]; j++) {
				if (a[i] % j == 0 && j <= m) {
					l.insert(j);
					if (a[i] / j <= m) {l.insert(a[i] / j);}
				}
			}
			if (l.size() >= m) {mx = i; break;}
		}
		// cout << mn << " " << mx << " found\n";
		res = min(res, a[mx] - a[mn]);
		if (res == 0) {cout << 0 << '\n'; return;}
	}
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
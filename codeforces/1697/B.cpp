#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, q;
	cin >> n >> q;
	long long a[n + 1], pref[n + 1];
	pref[0] = 0LL;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		pref[i] = a[i] + pref[i - 1];
	}
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		cout << pref[n - x + y] - pref[n - x] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	solve();
}
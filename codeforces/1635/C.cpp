#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (is_sorted(a, a + n)) {cout << 0 << '\n'; return;}
	if (a[n - 2] > a[n - 1]) {cout << -1 << '\n'; return;}
	if (a[n - 1] < 0) {cout << -1 << '\n'; return;}
	cout << n - 2 << '\n';
	for (int i = 1; i <= n - 2; i++) {
		cout << i << ' ' << n - 1 << ' ' << n << '\n';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
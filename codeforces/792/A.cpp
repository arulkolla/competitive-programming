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
	sort(a, a + n);
	int mn = 2 * MOD;
	for (int i = 1; i < n; i++) {
		mn = min(mn, a[i] - a[i - 1]);
	}
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] == mn) {cnt++;}
	}
	cout << mn << ' ' << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
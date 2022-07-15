#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[2 * n];
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}	
	sort(a, a + 2 * n);
	for (int i = 0; i < n; i++) {
		if (a[i + n] - a[i] < k) {cout << "NO\n"; return;}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
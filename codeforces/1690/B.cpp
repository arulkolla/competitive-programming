#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {cin >> a[i];}
	for (int i = 0; i < n; i++) {cin >> b[i];}
	int mx = -MOD;
	for (int i = 0; i < n; i++) {mx = max(mx, a[i] - b[i]);}
	if (mx < 0) {cout << "NO\n"; return;}
	for (int i = 0; i < n; i++) {if (max(a[i] - mx, 0) != b[i]) {cout << "NO\n"; return;}}
	cout << "YES\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
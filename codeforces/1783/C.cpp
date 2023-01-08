#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	int tot = 0, ind = -1; // good range = [0, ind)
	for (int i = 0; i < n; i++) {
		tot += b[i];
		if (tot > m) {ind = i; break;}
	}
	if (ind == -1) {cout << 1 << '\n'; return;}
	if (ind == 0) {cout << n + 1 << '\n'; return;}

	m -= a[ind];
	vector<int> c;
	for (int i = 0; i < n; i++) {
		if (i != ind) {c.push_back(a[i]);}
	}
	sort(c.begin(), c.end());
	tot = 0;
	for (int i = 0; i < ind - 1; i++) {
		tot += c[i];
	}
	if (tot <= m) {cout << n - ind << '\n';}
	else {cout << n - ind + 1 << '\n';}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
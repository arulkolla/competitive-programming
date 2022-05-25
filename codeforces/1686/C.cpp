#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	if (n % 2 == 1) {cout << "NO\n"; return;}
	int b[n];
	int l = 0, r = n / 2;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {b[i] = a[l]; l++;}
		else {b[i] = a[r]; r++;}
	}
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if (!((b[i] > b[(i - 1 + n) % n] && b[i] > b[(i + 1) % n]) || (b[i] < b[(i - 1 + n) % n] && b[i] < b[(i + 1) % n]))) {
			ok = false;
		}
	}
	if (!ok) {cout << "NO\n"; return;}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << b[i] << ' ';
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
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
	string s;
	bool bad = true;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1]) {s += '1'; bad = false;}
		else {s += '0';}
	}
	if (bad) {cout << 0 << '\n'; return;}
	int l, r;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == '1') {l = i; break;}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '1') {r = i; break;}
	}
	if (l == r) {cout << 0 << '\n';}
	else {cout << max(r - l - 1, 1) << '\n';}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
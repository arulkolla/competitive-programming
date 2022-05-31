#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int l = -1, r = -1, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {l = i; break;}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '1') {r = i; break;}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {cnt++;}
	}
	if (l == -1) {cout << 0 << '\n'; return;}
	int tot = cnt * 11;
	bool used = false;
	if (k >= n - 1 - r) {
		k -= (n - 1 - r); tot -= 10;
		if (l == r) {used = true;}
	}
	if (!used && k >= l) {k -= l; tot--;}
	cout << tot << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
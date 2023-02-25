#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0, l = MOD, r = -MOD;
	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n - 1 - i]) {cnt++; l = min(l, i); r = max(r, i);}
	}
	if (cnt == 0) {cout << "YES\n"; return;}
	cout << (r - l + 1 == cnt ? "YES\n" : "NO\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
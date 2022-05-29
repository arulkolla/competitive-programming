#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	string s[n];
	bool ok[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		ok[i] = false;
	}
	string curr;
	int mx = -MOD, mn = MOD;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		x--;
		mx = max(mx, (int)s[x].length());
		mn = min(mn, (int)s[x].length());
		curr = s[x];
		ok[x] = true;
	}
	if (mn != mx) {cout << "No\n"; return;}
	for (int i = 0; i < n; i++) {
		if (ok[i]) {
			for (int j = 0; j < mn; j++) {
				if (s[i][j] != curr[j]) {curr[j] = '?';}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (!ok[i] && s[i].length() == mn) {
			bool fine = true;
			for (int j = 0; j < curr.length(); j++) {
				if (curr[j] != '?') {
					fine &= (s[i][j] == curr[j]);
				}
			}
			if (fine) {cout << "No\n"; return;}
		}
	}
	cout << "Yes\n" << curr << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
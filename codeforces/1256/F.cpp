#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	string ss = s, ts = t;
	sort(ss.begin(), ss.end());
	sort(ts.begin(), ts.end());
	if (ss != ts) {cout << "NO\n"; return;}
	for (int i = 1; i < n; i++) {
		if (ss[i] == ss[i - 1]) {cout << "YES\n"; return;}
	}
	int pos[26] = {};
	for (int i = 0; i < n; i++) {
		pos[t[i] - 'a'] = i; 
	}
	int ok = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (pos[s[i] - 'a'] > pos[s[j] - 'a']) {ok ^= 1;}
		}
	}
	cout << (ok ? "NO\n" : "YES\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
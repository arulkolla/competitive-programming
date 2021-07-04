#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	bool has = false;
	string pref = "", suff = "";
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') {has = true;}
		else if (!has) {pref += s[i];}
		else {suff += s[i];}
	}
	if (!has) {cout << (s == t ? "YES" : "NO"); return;}
	for (int i = 0; i < pref.length(); i++) {
		if (t[i] != pref[i]) {cout << "NO"; return;}
	}
	for (int i = 0; i < suff.length(); i++) {
		if (t[m - i - 1] != suff[suff.length() - i - 1]) {cout << "NO"; return;}
		if (m - i - 1 < pref.length()) {cout << "NO"; return;}
	}
	cout << "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
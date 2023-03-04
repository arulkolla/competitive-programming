#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s = "!", t;
	for (int i = 0; i < 2 * n - 2; i++) {
		string x;
		cin >> x;
		if (x.length() == n - 1) {
			if (s == "!") {s = x;}
			else {t = x;}
		}
	}	
	bool ok = true;
	for (int i = 0; i < n - 2; i++) {
		if (s[i] != t[i + 1]) {ok = false;}
	}
	// cout << ok << ' ';
	string ss;
	if (!ok) {
		s += t[n - 2];
		ss = s;
		// cout << ss << '\n';
		reverse(ss.begin(), ss.end());
		if (ss == s) {cout << "YES\n";}
		else {cout << "NO\n";}	
	}
	else {
		t += s[n - 2];
		ss = t;
		// cout << ss << '\n';
		reverse(ss.begin(), ss.end());
		if (ss == t) {cout << "YES\n";}
		else {cout << "NO\n";}	
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
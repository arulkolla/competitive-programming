#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if (s[i] != s[0]) {ok = false;}
	}
	if (ok) {
		if (s[0] == '0') {cout << 1 << '\n';}
		else {cout << 0 << '\n';}
	}
	else {
		char prev = s[0];
		int cnt = 0;
		for (int i = 1; i < n; i++) {
			if (s[i] != prev) {
				if (prev == '0') {cnt++;}
				prev = s[i];
			}
		}
		if (prev == '0') {cnt++;}
		cout << min(cnt, 2) << '\n';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
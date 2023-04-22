#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if (s[i] == '|') {
			if (ok == true) {ok = false;}
			else {ok = true;}
		}
		else if (s[i] == '*') {
			if (ok == true) {
				cout << "out\n"; return;
			}
			else {
				cout << "in\n"; return;
			}
		}
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	solve();
}
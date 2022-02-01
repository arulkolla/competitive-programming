#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int bal = 0;
	for (char c : s) {
		if (c == '0') {bal++;}
		else {bal--;}
	}
	if (bal != 0) {cout << "1\n" << s;}
	else {
		cout << "2\n";
		cout << s.substr(0, n - 1) << ' ' << s[n - 1];
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
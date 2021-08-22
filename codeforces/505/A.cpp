#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i <= n; i++) {
		for (char c = 'a'; c <= 'z'; c++) {
			string t = s.substr(0, i) + c + s.substr(i, n), tr = t;
			reverse(tr.begin(), tr.end());
			if (t == tr) {cout << t; return;}
		}
	}
	cout << "NA";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
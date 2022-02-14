#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	string s, t;
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	int n = s.length(), curr = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == t[curr]) {curr++;}
		else {i++;}
		if (curr == t.length()) {cout << "YES\n"; return;}
	}
	cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
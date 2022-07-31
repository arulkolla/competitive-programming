#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	for (int i = 0; i < m - 1; i++) {if (s[i] != t[i]) {cout << "NO\n"; return;}}
	for (int i = m - 1; i < n; i++) {if (s[i] == t[m - 1]) {cout << "YES\n"; return;}}
	cout << "NO\n";	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
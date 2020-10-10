
// Problem: D1. Remove the Substring (easy version)
// Contest: Codeforces - Codeforces Round #579 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1203/D1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	string s, t;
	cin >> s >> t;
	int mx = 0, n = s.size();
	for (int l = 0; l < n; l++) {
		for (int r = l; r < n; r++) {
			string q;
			for (int i = 0; i < l; i++) {q += s[i];}
			for (int i = r + 1; i < n; i++) {q += s[i];}
			int lastSeen = 0;
			for (int i = 0; i < q.size(); i++) {
				if (q[i] == t[lastSeen]) {lastSeen++;}
				if (lastSeen >= t.size()) {mx = max(mx, n - (int)q.size()); break;}
			}
		}
	}
	cout << mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
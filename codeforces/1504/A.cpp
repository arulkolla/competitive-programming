// Problem: A.  Déjà Vu
// Contest: Codeforces - Codeforces Round #712 (Div. 2)
// URL: https://codeforces.com/contest/1504/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	string s;
	cin >> s;
	bool bad = true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 'a') {
			s.insert(s.size() - i, "a");
			bad = false;
			break;
		}
	}
	if (bad) {cout << "NO" << endl;}
	else {cout << "YES" << endl << s << endl;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
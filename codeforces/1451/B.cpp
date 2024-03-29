
// Problem: B. Non-Substring Subsequence
// Contest: Codeforces - Codeforces Round #685 (Div. 2)
// URL: https://codeforces.com/contest/1451/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	for (int qq = 0; qq < q; qq++) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		bool ok1 = false, ok2 = false;
		for (int i = 0; i < l; i++) {
			if (s[i] == s[l]) {ok1 = true;}
		}
		for (int i = r + 1; i < n; i++) {
			if (s[i] == s[r]) {ok2 = true;}
		}
		cout << ((ok1 || ok2) ? "YES" : "NO") << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
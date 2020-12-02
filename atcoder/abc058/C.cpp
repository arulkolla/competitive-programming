
// Problem: C - Dubious Document
// Contest: AtCoder - AtCoder Beginner Contest 058
// URL: https://atcoder.jp/contests/abc058/tasks/arc071_a
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cnts[57][26];
	for (int i = 0; i < n; i++) {
		int cnt[26] = {};
		for (char c : a[i]) {
			cnt[c - 'a']++;
		}
		for (int j = 0; j < 26; j++) {
			cnts[i][j] = cnt[j];
		}
	}
	int res[26] = {};
	for (int i = 0; i < 26; i++) {res[i] = MOD;}
	for (int j = 0; j < 26; j++) {
		for (int i = 0; i < n; i++) {
			res[j] = min(res[j], cnts[i][j]);
		}	
	}
	string ans;
	for (int j = 0; j < 26; j++) {
		for (int i = 0; i < res[j]; i++) {
			ans += ('a' + j);
		}
	}
	cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
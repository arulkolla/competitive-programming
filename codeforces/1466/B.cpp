
// Problem: B. Last minute enhancements
// Contest: Codeforces - Good Bye 2020
// URL: https://codeforces.com/contest/1466/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	bool mp[2 * n + 7];
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 2 * n + 7; i++) {
		mp[i] = false;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (!mp[a[i]]) {mp[a[i]] = true; cnt++;}
		else if (!mp[a[i] + 1]) {mp[a[i] + 1] = true; cnt++;}
	}
	cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
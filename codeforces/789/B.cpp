
// Problem: B. Masha and geometric depression
// Contest: Codeforces - Codeforces Round #407 (Div. 2)
// URL: https://codeforces.com/contest/789/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100007;
const int MOD = 1000000007;

void solve() {
	long long b, q, l, n;
	cin >> b >> q >> l >> n;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x] = 1;
	}
	int res = 0;
	for (int i = 0; i < 100; i++) {
		if (abs(b) > l) {break;}
		if (!mp[b]) {res++;}
		b *= q;
	}
	if (res > 40) {cout << "inf"; return;} cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
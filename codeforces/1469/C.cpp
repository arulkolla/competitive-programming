
// Problem: C. Building a Fence
// Contest: Codeforces - Educational Codeforces Round 101 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1469/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long k;
	cin >> n >> k;
	long long h[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	long long l = h[0] + 1 - k, r = h[0] + k - 1;
	//cout << h[0] << " " << l << " " << r << endl;
	for (int i = 1; i < n - 1; i++) {
		long long newl = h[i], newr = h[i] + k - 1;
		if (newl > r || newr < l) {cout << "NO" << endl; return;}
		l = max(newl, l) + 1 - k;
		r = min(newr, r) + k - 1;
	}
	if (l <= h[n - 1] && h[n - 1] <= r) {cout << "YES" << endl;}
	else {cout << "NO" << endl;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
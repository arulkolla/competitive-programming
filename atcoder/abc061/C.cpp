
// Problem: C - Big Array
// Contest: AtCoder - AtCoder Beginner Contest 061
// URL: https://atcoder.jp/contests/abc061/tasks/abc061_c
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
	pair<long long, long long> a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	long long tot = 0;
	for (int i = 0; i < n; i++) {
		if (tot <= k && k <= tot + a[i].second) {cout << a[i].first; return;}
		tot += a[i].second;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
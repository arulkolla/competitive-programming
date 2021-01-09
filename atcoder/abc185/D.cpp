
// Problem: D - Stamp
// Contest: AtCoder - AtCoder Beginner Contest 185
// URL: https://atcoder.jp/contests/abc185/tasks/abc185_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {	
	long long n, a[MAX];
	int m;
	cin >> n >> m;
	a[0] = 0;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	a[m + 1] = n + 1;
	sort(a, a + m + 1);
	long long res = 0, mn = MOD;
	vector<long long> diffs;
	for (int i = 0; i <= m; i++) {
		long long diff = a[i + 1] - a[i] - 1;
		if (diff > 0) {
			diffs.push_back(diff);
			mn = min(mn, diff);	
		}
	}
	
	for (long long i : diffs) {
		res += (i + mn - 1) / mn;
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
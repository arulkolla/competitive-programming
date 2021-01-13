
// Problem: B. Three-level Laser
// Contest: Codeforces - VK Cup 2018 - Round 2
// URL: https://codeforces.com/contest/924/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long u;
	cin >> n >> u;
	long long a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long double res = -1;
	for (int i = 0; i < n - 1; i++) {
		auto pos = upper_bound(a + i, a + n, a[i] + u) - a;
		pos--;
		if (pos <= i + 1) {continue;}
		// cout << a[i] << ' ' << a[i + 1] << ' ' << pos << ' ' << a[pos] << endl;
		res = max(res, (long double)(a[pos] - a[i + 1]) / (a[pos] - a[i]));
	}
	cout << fixed << setprecision(17) << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
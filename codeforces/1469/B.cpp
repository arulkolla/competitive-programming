
// Problem: B. Red and Blue
// Contest: Codeforces - Educational Codeforces Round 101 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1469/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long a[n + 7], ap[n + 7];
	ap[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ap[i] = ap[i - 1] + a[i];
	}
	int m;
	cin >> m;
	long long b[m + 7], bp[m + 7];
	bp[0] = 0;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		bp[i] = bp[i - 1] + b[i];
	}
	long long res = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			res = max(res, bp[j] + ap[i]);
		}
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
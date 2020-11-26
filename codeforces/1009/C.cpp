
// Problem: C. Annoying Present
// Contest: Codeforces - Educational Codeforces Round 47 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1009/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n, m;
	cin >> n >> m;
	long long res = 0;
	for (int i = 0; i < m; i++) {
		long long x, d;
		cin >> x >> d;
		res += n * x;
		if (d > 0) {
			d *= (n * (n - 1)) / 2;
		}
		else if (n % 2) {
			d *= ((n - 1) / 2) * ((n + 1) / 2);
		}
		else {
			d *= (((n - 1) / 2) * ((n + 1) / 2) + n / 2);
		}
		res += d;
	}
	cout << fixed << setprecision(17) << res / (long double) n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
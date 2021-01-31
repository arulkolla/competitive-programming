
// Problem: A. Save Energy!
// Contest: Codeforces - Codeforces Round #467 (Div. 1)
// URL: https://codeforces.com/contest/936/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long k, d, t;
	cin >> k >> d >> t;
	t *= 2;
	long long p = d * ((k + d - 1) / d), q = p - k;
	long long cnt = t / (2 * k + q), left = t % (2 * k + q);
	long double res = 0;
	res += cnt * (k + q);
	if (left <= 2 * k) {
		// whatever's left will be cooked on the stove
		res += (left / (long double)2.0);
	}
	else {
		res += k;
		left -= 2 * k;
		// stove off
		res += left;
	}
	cout << fixed << setprecision(17) << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}

// Problem: C. Unfair Poll
// Contest: Codeforces - Codeforces Round #392 (Div. 2)
// URL: https://codeforces.com/contest/758/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long n, m, k;

long long num(long long x, long long y) {
	if (n == 1) {return k / m + (k % m >= y);}
	long long tot = k / (n * m * 2 - 2 * m), left = k % (n * m * 2 - 2 * m);
	long long pos = m * x - m + y;
	if (x == 1 || x == n) {return tot + (pos <= left);}
	else {return 2 * tot + (pos <= left) + (m * n + n * m - x * m - m + y <= left);}
}

void solve() {
	long long x, y;
	cin >> n >> m >> k >> x >> y;
	cout << max(num(1, 1), max(num(n - 1, 1), num(2, 1))) << " ";
	cout << num(n, m) << " ";
	cout << num(x, y) << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
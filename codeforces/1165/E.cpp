
// Problem: E. Two Arrays and Sum of Functions
// Contest: Codeforces - Codeforces Round #560 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1165/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	long long a[n + 7];
	for (int i = 0; i < n; i++) {cin >> a[i];}
	long long b[n + 7];
	for (int i = 0; i < n; i++) {cin >> b[i];}
	long long cnt[n + 7];
	for (int i = 0; i < n; i++) {cnt[i] = a[i] * (n - i) * (i + 1);}
	sort(b, b + n);
	sort(cnt, cnt + n);
	long long res  = 0;
	for (int i = 0; i < n; i++) {
		res += ((cnt[i] % MOD) * (b[n - 1 - i] % MOD)) % MOD;
		res %= MOD;
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
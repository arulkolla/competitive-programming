// Problem: B. Replace and Keep Sorted
// Contest: Codeforces - Codeforces Round #701 (Div. 2)
// URL: https://codeforces.com/contest/1485/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, q;
	long long k;
	cin >> n >> q >> k;
	long long a[n + 7], diff[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		diff[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		diff[i] += diff[i - 1];
		diff[i] += a[i + 1] - a[i] - 1;
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		long long res = diff[r - 1] - diff[l - 1];
		res *= 2;
		res += a[l] - 1;
		res += k - a[r];
		cout << res << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
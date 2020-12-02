
// Problem: C. Find Pair
// Contest: Codeforces - Codeforces Round #111 (Div. 2)
// URL: https://codeforces.com/contest/160/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;
#define int long long
void solve() {
	int n, k;
	cin >> n >> k;
	k--;
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int res = k / n, cnt = 0, tot = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == a[res]) {cnt++;}
		else if (a[i] < a[res]) {tot++;}
		else {break;}
	}
	cout << a[res] << " " << a[(k - n * tot) / cnt];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
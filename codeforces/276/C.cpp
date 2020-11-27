
// Problem: C. Little Girl and Maximum Sum
// Contest: Codeforces - Codeforces Round #169 (Div. 2)
// URL: https://codeforces.com/contest/276/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, q;
	cin >> n >> q;
	unsigned long long a[MAX] = {};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	unsigned long long diff[MAX] = {};
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		diff[l]++;
		diff[r + 1]--;
	}
	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
	}
	sort(diff + 1, diff + n + 1);
	sort(a + 1, a + n + 1);
	unsigned long long res = 0;
	for (int i = 1; i <= n; i++) {
		// cout << a[i] << " " << diff[i] << endl;
		res += a[i] * diff[i];
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
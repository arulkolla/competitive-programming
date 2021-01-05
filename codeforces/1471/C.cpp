
// Problem: C. Strange Birthday Party
// Contest: Codeforces - Codeforces Round #694 (Div. 2)
// URL: https://codeforces.com/contest/1471/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	long long gift[m + 7];
	for (int i = 0; i < m; i++) {
		cin >> gift[i];
	}
	sort(a, a + n, greater<int>());
	long long res = 0;
	int lastNot = 0;
	for (int i = 0; i < n; i++) {
		if (lastNot >= a[i]) {
			// give money
			res += gift[a[i]];
		}
		else {
			// give lastNot
			res += gift[lastNot];
			lastNot++;
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
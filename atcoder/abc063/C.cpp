
// Problem: C - Bugged
// Contest: AtCoder - AtCoder Beginner Contest 063
// URL: https://atcoder.jp/contests/abc063/tasks/arc075_a
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % 10) {cout << sum; return;}
	int mn = MOD;
	for (int i = 0; i < n; i++) {
		if (a[i] % 10) {mn = min(mn, a[i]);}
	}
	if (mn == MOD) {cout << 0;}
	else {cout << sum - mn;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
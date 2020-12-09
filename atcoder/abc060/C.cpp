
// Problem: C - Sentou
// Contest: AtCoder - AtCoder Beginner Contest 060
// URL: https://atcoder.jp/contests/abc060/tasks/arc073_a
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long t;
	cin >> n >> t;
	long long a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	} 
	long long res = t;
	for (int i = 1; i < n; i++) {
		long long diff = a[i] - a[i - 1];
		if (diff >= t) {res += t;}
		else {res += diff;}
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
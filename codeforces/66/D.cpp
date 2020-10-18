
// Problem: D. Petya and His Friends
// Contest: Codeforces - Codeforces Beta Round #61 (Div. 2)
// URL: https://codeforces.com/problemset/problem/66/D
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
	if (n == 2) {cout << -1 << endl; return;}
	cout << 6 << endl;
	cout << 10 << endl;
	cout << 15 << endl;
	unsigned long long res = 30;
	for (int i = 3; i < n; i++) {res *= 2; cout << res << endl;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
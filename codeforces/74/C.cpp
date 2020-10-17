
// Problem: C. Chessboard Billiard
// Contest: Codeforces - Codeforces Beta Round #68
// URL: https://codeforces.com/contest/74/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long gcd(long long a, long long b) {
	if (b == 0) {return a;}
	return gcd(b, a % b);
}

void solve() {
	long long p, q;
	cin >> p >> q;
	cout << gcd(p - 1, q - 1) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
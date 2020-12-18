
// Problem: A. LCM Challenge
// Contest: Codeforces - Codeforces Round #146 (Div. 1)
// URL: https://codeforces.com/problemset/problem/235/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n;
	cin >> n;
	if (n == 1) {cout << 1;}
	else if (n == 2) {cout << 2;}
	else if (n % 2) {cout << n * (n - 1) * (n - 2);}
	else if (n % 3) {cout << n * (n - 1) * (n - 3);}
	else {cout << (n - 1) * (n - 2) * (n - 3);}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
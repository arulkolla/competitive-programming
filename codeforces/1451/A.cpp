
// Problem: A. Subtract or Divide
// Contest: Codeforces - Codeforces Round #685 (Div. 2)
// URL: https://codeforces.com/contest/1451/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n;
	cin >> n;
	if (n == 1) {cout << 0 << endl;}
	else if (n == 2) {cout << 1 << endl;}
	else if (n == 3) {cout << 2 << endl;}
	else if (n % 2) {cout << 3 << endl;}
	else {cout << 2 << endl;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
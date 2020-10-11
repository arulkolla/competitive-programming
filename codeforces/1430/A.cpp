
// Problem: A. Number of Apartments
// Contest: Codeforces - Educational Codeforces Round 96 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1430/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n; cin >> n;
	if (n == 1 || n == 2 || n == 4) {cout << -1 << endl;}
	else if (n == 3) {cout << "1 0 0" << endl;}
	else if (n == 5) {cout << "0 1 0" << endl;}
	else {
		if (n % 3 == 0) {
			cout << n/3 << " " << 0 << " " << 0 << endl;
		}
		else if (n % 3 == 1) {
			cout << (n-7)/3 << " " << 0 << " " << 1 << endl;
		}
		else {
			cout << (n-8)/3 + 1 << " " << 1 << " " << 0 << endl;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}

// Problem: A. Bachgold Problem
// Contest: Codeforces - Codeforces Round #388 (Div. 2)
// URL: https://codeforces.com/problemset/problem/749/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	if (n % 2) {
		cout << (n - 1) / 2 << endl;
		cout << 3 << " ";
		for (int i = 1; i < (n - 1) / 2; i++) {
			cout << 2 << " ";
		}
	}
	else {
		cout << n / 2 << endl;
		for (int i = 0; i < n / 2; i++) {
			cout << 2 << " ";
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
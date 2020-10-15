
// Problem: A. Plus and Square Root
// Contest: Codeforces - Codeforces Round #372 (Div. 1)
// URL: https://codeforces.com/contest/715/problem/A
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
	for (long long i = 1; i <= n; i++) {
		if (i == 1) {
			cout << 2 << endl;
		}
		else {
			cout << i * i * i + 2 * i * i + 1 << endl;
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

// Problem: A. Add Candies
// Contest: Codeforces - Codeforces Round #683 (Div. 2, by Meet IT)
// URL: https://codeforces.com/contest/1447/problem/A
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
	cout << n - 1 << endl;
	for (int i = 2; i <= n; i++) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
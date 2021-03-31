// Problem: E. Tetrahedron
// Contest: Codeforces - Codeforces Round #113 (Div. 2)
// URL: https://codeforces.com/problemset/problem/166/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long back = 1, prev = 0, curr = 0;
	if (n == 0) {cout << back; return;}
	if (n == 1) {cout << prev; return;}
	for (int i = 2; i <= n; i++) {
		curr = 2 * prev + 3 * back;
		curr %= MOD;
		if (i == n) {cout << curr; return;}
		back = prev;
		prev = curr;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
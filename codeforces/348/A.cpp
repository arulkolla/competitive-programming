
// Problem: A. Mafia
// Contest: Codeforces - Codeforces Round #202 (Div. 1)
// URL: https://codeforces.com/contest/348/problem/A
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
	long long sum = 0, q, mx = -1;
	for (int i = 0; i < n; i++) {
		cin >> q;
		mx = max(q, mx);
		sum += q;
	}
	cout << max((sum + n - 2) / (n - 1), mx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
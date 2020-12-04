
// Problem: G. Special Permutation
// Contest: Codeforces - Codeforces Round #640 (Div. 4)
// URL: https://codeforces.com/contest/1352/problem/G
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
	if (n < 4) {cout << -1 << endl; return;}
	int val = n; if (n % 2 == 0) {val--;}
	for (int i = val; i >= 1; i -= 2) {cout << i << " ";}
	cout << 4 << " ";
	cout << 2 << " ";
	for (int i = 6; i <= n; i += 2) {cout << i << " ";}
	cout << endl; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
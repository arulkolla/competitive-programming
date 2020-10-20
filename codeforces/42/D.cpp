
// Problem: D. Strange town
// Contest: Codeforces - Codeforces Beta Round #41
// URL: https://codeforces.com/contest/42/problem/D
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
	int a[20] = {0, 1, 3, 7, 12, 20, 30, 44, 65, 80, 96, 122, 147, 181, 203, 251, 289, 360, 400, 474};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] == a[j]) {cout << 0 << " ";}
			else {cout << a[i] + a[j] << " ";}
		}
		cout << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
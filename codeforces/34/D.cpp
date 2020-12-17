
// Problem: D. Road Map
// Contest: Codeforces - Codeforces Beta Round #34 (Div. 2)
// URL: https://codeforces.com/problemset/problem/34/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, r1, r2;
	cin >> n >> r1 >> r2;
	int par[n + 7];
	for (int i = 1; i <= n; i++) {
		if (i == r1) {par[i] = -1;}
		else {cin >> par[i];}
	}
	int curr = r2;
	vector<int> v;
	while (par[curr] != -1) {
		v.push_back(curr);
		curr = par[curr];
	}
	v.push_back(r1);
	for (int i = 1; i < v.size(); i++) {
		par[v[i]] = v[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		if (i != r2) {cout << par[i] << " ";}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
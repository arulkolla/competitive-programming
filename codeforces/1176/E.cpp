
// Problem: E. Cover it!
// Contest: Codeforces - Codeforces Round #565 (Div. 3)
// URL: https://codeforces.com/contest/1176/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

vector<int> par(MAX);
vector<bool> vis(MAX);
vector<vector<int> > g(MAX);
int n, m;

void dfs(int v) {
	vis[v] = true;
	for (int i : g[v]) {
		if (!vis[i]) {
			par[i] = par[v] + 1;
			dfs(i);
		}
	}	
}

void zero() {
	for (int i = 1; i <= n + 7; i++) {g[i].clear();}
	for (int i = 1; i <= n + 7; i++) {par[i] = 0;}
	for (int i = 0; i <= n + 7; i++) {vis[i] = false;}
	par[1] = 0;
}

void solve() {
	cin >> n >> m;
	zero();
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	vector<int> odd, even;
	for (int i = 1; i <= n; i++) {
		if (par[i] % 2 == 0) {even.push_back(i);}
		else {odd.push_back(i);}
	}
	if (odd.size() <= n / 2) {
		cout << odd.size() << endl;
		for (int i : odd) {cout << i << " ";} cout << endl;
	}
	else {
		cout << even.size() << endl;
		for (int i : even) {cout << i << " ";} cout << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}

// Problem: E. Military Problem
// Contest: Codeforces - Codeforces Round #498 (Div. 3)
// URL: https://codeforces.com/contest/1006/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

vector<int> g[MAX];
bool vis[MAX];
int sz[MAX];
vector<int> arr;

void dfs(int v) {
	sz[v] = 1;
	vis[v] = true;
	arr.push_back(v);
	for (int i : g[v]) {
		if (!vis[i]) {
			dfs(i);
			sz[v] += sz[i];
		}
	}
}

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		int u;
		cin >> u;
		g[i].push_back(u);
		g[u].push_back(i);
	}
	dfs(1);
	// for (int i : arr) {cout << i << ' ';} cout << endl;
	int mp[n + 7];
	for (int i = 0; i < n; i++) {
		mp[arr[i]] = i;
	}
	// for (int i = 1; i <= n; i++) {cout << sz[i] << ' ';} cout << endl;
	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		v--;
		if (v >= sz[u]) {cout << -1 << endl;}
		else {cout << arr[mp[u] + v] << endl;}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
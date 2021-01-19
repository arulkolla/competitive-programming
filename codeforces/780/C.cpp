
// Problem: C. Andryusha and Colored Balloons
// Contest: Codeforces - Технокубок 2017 - Финал (только для онсайт-финалистов)
// URL: https://codeforces.com/contest/780/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

vector<int> g[MAX];
int res[MAX];
bool vis[MAX], mp[MAX] = {};

void dfs(int v) {
	vis[v] = true;
	int curr = 0;
	for (int i : g[v]) {
		if (vis[i]) {mp[res[i]] = true;}
	}
	mp[res[v]] = true;
	for (int i : g[v]) {
		if (!vis[i]) {
			curr++;
			while (mp[curr]) {curr++;}
			res[i] = curr;
		}
	}
	mp[res[v]] = false;
	for (int i : g[v]) {
		mp[res[i]] = false;
	}
	for (int i : g[v]) {
		mp[res[i]] = false;
		if (!vis[i]) {
			dfs(i);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int mx = -1, mxN;
	for (int i = 1; i <= n; i++) {
		if ((int)g[i].size() > mx) {
			mx = (int)g[i].size();
			mxN = i;
		}
	}
	res[mxN] = 1;
	dfs(mxN);
	cout << mx + 1 << endl;
	for (int i = 1; i <= n; i++) {
		cout << res[i] << ' ';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
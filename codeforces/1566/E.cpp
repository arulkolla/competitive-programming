#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int n;
vector<int> g[MAX], child[MAX];
bool vis[MAX] = {}, used[MAX] = {};
int par[MAX] = {}, color[MAX] = {};

void dfs(int v) {
	vis[v] = true;
	for (int i : g[v]) {
		if (!vis[i]) {
			par[i] = v;
			child[v].push_back(i);
			dfs(i);
		}
	}
}

int dp(int v) {
	if (color[v] == 0) {
		bool ok = false;
		for (int i : child[v]) {
			if (dp(i) == 1) {
				ok = true;	
			}
		}
		if (ok) {color[v] = 2;}
		else {
			if (par[v] == 1) {color[v] = 3;}
			else {color[v] = 1;}
		}
	}
	return color[v];
}

void clear() {
	for (int i = 0; i < n + 5; i++) {
		g[i].clear();
		child[i].clear();
		vis[i] = false;
		used[i] = false;
		par[i] = -1;
		color[i] = 0;
	}
}

void solve() {
	clear();
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	dp(1);
	int res = 0, r3 = 0;
	for (int i = 2; i <= n; i++) {
		if (color[i] == 1) {res++;}
		else if (color[i] == 2) {res--;}
		else {r3++;}
	} 
	if (r3 > 1) {res += (r3 - 1);}
	cout << res + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
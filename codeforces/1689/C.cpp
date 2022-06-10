#include <bits/stdc++.h>

using namespace std;

const int MAX = 300007;
const int MOD = 1000000007;

vector<int> g[MAX], child[MAX];
int dp[MAX], eq[MAX];
bool vis[MAX], used[MAX];

void dfs(int v) {
	vis[v] = true;
	for (int i : g[v]) {
		if (!vis[i]) {
			child[v].push_back(i);
			dfs(i);
		}
	}
}

int f(int v) {
	if (dp[v] != MOD) {return dp[v];}
	if (child[v].size() == 0) {dp[v] = 1; return dp[v];}
	dp[v] = 1;
	int c1 = f(child[v][0]), c2;
	if (child[v].size() == 2) {c2 = f(child[v][1]);}
	else {c2 = 0;}
	dp[v] += c1 + c2;
	return dp[v];
}

int gg(int v) {
	// cout << "at " << v << '\n';
	if (eq[v] != MOD) {return eq[v];}
	if (child[v].size() == 0) {eq[v] = 0;}
	else if (child[v].size() == 1) {
		eq[v] = dp[child[v][0]] - 1;
	}
	else {
		eq[v] = max(gg(child[v][0]) + dp[child[v][1]] - 1, gg(child[v][1]) + dp[child[v][0]] - 1);
	}
	// cout << v << " gave " << eq[v] << '\n';
	return eq[v];
}

void allc(int n) {
	for (int i = 0; i < n + 5; i++) {
		g[i].clear();
		child[i].clear();
		dp[i] = MOD;
		vis[i] = false;
		used[i] = false;
		eq[i] = MOD;
	}
}

void solve() {
	int n;
	cin >> n;
	allc(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	f(1);
	cout << gg(1) << '\n';
	// for (int i = 1; i <= n; i++) {cout << i << ' ' << dp[i] << '\n';} cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
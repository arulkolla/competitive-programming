#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

vector<int> g[MAX];
bool vis[MAX];
int par[MAX], dp[MAX], a[MAX];
vector<int> child[MAX];
int n, k, x;

void dfs(int v) {
	vis[v] = true;
	for (int i : g[v]) {
		if (!vis[i]) {
			child[v].push_back(i);
			par[i] = v;
		}
	}
	for (int i : g[v]) {
		if (!vis[i]) {
			dfs(i);
		}
	}
}

int f(int v) {
	dp[v] = a[v];
	for (int i : child[v]) {
		dp[v] ^= f(i);
	}
	return dp[v];
}

int findval(int val, int v) {
	bool ok = false;
	int res = -1;
	for (int i : child[v]) {
		if (findval(val, i) != -1) {res = findval(val, i);}
	}
	if (res == -1 && dp[v] == val) {res = v;}
	return res;
}

void clear() {
	x = 0;
	for (int i = 0; i < n + 7; i++) {
		g[i].clear();
		child[i].clear();
		par[i] = -1;
		dp[i] = -1;
		vis[i] = false;
	}
}

void solve() {
	cin >> n >> k;
	clear();
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		x ^= a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	f(1);
	if (x == 0) {
		// delete 1 edge
		cout << "YES\n";
	}
	else {
		// delete 2 edges
		if (k == 2) {cout << "NO\n"; return;}
		vector<int> has;
		for (int i = 2; i <= n; i++) {
			if (dp[i] == x) {has.push_back(i);}
		}
		if (has.empty()) {cout << "NO\n"; return;}
		int rt = findval(x, 1);
		vector<int>::iterator pos = find(child[par[rt]].begin(), child[par[rt]].end(), rt);
		if (pos != child[par[rt]].end()) {
			child[par[rt]].erase(pos);
		}
		f(1);
		if (findval(x, 1) != -1) {cout << "YES\n"; return;}
		else {cout << "NO\n"; return;}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
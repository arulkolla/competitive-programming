#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int n, m;
vector<pair<int, bool> > g[MAX];
vector<pair<int, int> > pos;
pair<int, int> rn;
int color[MAX];
bool vis[MAX];
bool bad = false;

void dfs(int v) {
	if (color[v] == 1) {rn.first++;}
	else {rn.second++;}
	vis[v] = true;
	for (auto p : g[v]) {
		if (vis[p.first]) {
			if (p.second && color[p.first] != color[v]) {bad = true;}
			if (!p.second && color[p.first] != (color[v] == 1 ? 2 : 1)) {bad = true;}
		}
	}
	for (auto p : g[v]) {
		if (!vis[p.first]) {
			if (p.second) {
				color[p.first] = color[v];
			}
			else {
				color[p.first] = (color[v] == 1 ? 2 : 1);
			}
			dfs(p.first);	
		}
	}
}

void clear() {
	pos.clear();
	for (int i = 0; i < n + 7; i++) {
		g[i].clear();
		vis[i] = false;
		color[i] = 0;
	}
	bad = false;
}

void solve() {
	cin >> n >> m;
	clear();
	for (int i = 0; i < m; i++) {
		int u, v;
		string s;
		cin >> u >> v >> s;
		if (s == "crewmate") {
			g[u].emplace_back(v, true);
			g[v].emplace_back(u, true);
		}
		if (s == "imposter") {
			g[u].emplace_back(v, false);
			g[v].emplace_back(u, false);
		}	
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			rn.first = 0; rn.second = 0;
			color[i] = 1;
			dfs(i);
			pos.push_back(rn);
		}
	}
	int res = 0;
	if (bad) {cout << -1 << '\n'; return;}
	for (auto p : pos) {
		res += max(p.first, p.second);
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

vector<int> g[MAX], child[MAX];
vector<pair<int, int> > edges;
bool vis[MAX] = {};
map<pair<int, int>, int> color;
int n, m, par[MAX];

void dfs(int v) {
	vis[v] = true;
	for (int i : g[v]) {
		if (!vis[i]) {
			child[v].push_back(i);
			par[i] = v;
			dfs(i);
		}
	}
}

void col(int v) {
	int curr = 0;
	for (int i : child[v]) {
		curr++;
		if (v != 1 && color[make_pair(par[v], v)] == curr) {curr++;}
		if (curr > m) {curr = 1;}
		color[make_pair(v, i)] = curr;
		color[make_pair(i, v)] = curr;
		col(i);
	}
}

void solve() {
	int k;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		edges.emplace_back(u, v);
	}
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		v.push_back((int)(g[i].size()));
	}
	sort(v.begin(), v.end(), greater<int>());
	m = v[k];
	cout << m << '\n';
	dfs(1);
	col(1);
	for (auto p : edges) {
		cout << color[make_pair(p.first, p.second)] << ' ';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
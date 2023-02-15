#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

struct DSU {
	vector<int> e;
	DSU(int N) {e = vector<int>(N, -1);}
	int get(int x) {return e[x] < 0 ? x : e[x] = get(e[x]);}
	bool same_set(int a, int b) {return get(a) == get(b);}
	int size(int x) {return -e[get(x)];}
	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	DSU dsu(n + 7);
	vector<int> g[n + 7];
	bool vis[n + 7];
	int d[n + 7];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		dsu.unite(u, v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	if (dsu.size(1) != n) {cout << "NO\n"; return;}
	cout << "YES\n";
	
	for (int i = 1; i <= n; i++) {
		vis[i] = false;
		d[i] = 0;
	}
	
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : g[v]) {
			if (!vis[u]) {
				d[u] = d[v] + 1;
				vis[u] = true;
				q.push(u);
			}
		}
	}
	
	vector<pair<int, int>> pri;
	int color[n + 1];
	for (int i = 1; i <= n; i++) {
		pri.emplace_back(d[i], i);
		color[i] = 2;
	}
	sort(pri.begin(), pri.end());
	for (auto p : pri) {
		int h = p.first, v = p.second;
		if (color[v] != 2) {continue;}
		if (h < 2) {color[v] = 1 - h; continue;}
		for (int u : g[v]) {
			color[u] = 0;	
		}
		color[v] = 1;
	}
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (color[i] == 1) {res.push_back(i);}
	}
	cout << res.size() << '\n';
	for (int i : res) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
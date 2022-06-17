#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

vector<int> g[MAX];
bool vis[MAX], lvis[MAX], cyc[MAX];
int par[MAX];
int loop, lend;

void dfs(int v) {
	vis[v] = true;
	for (int i : g[v]) {
		if (!vis[i]) {
			par[i] = v;
			dfs(i);
		}
		else if (i != par[v]) {
			loop = i;
			lend = v;
		}
	}
}

void allc(int n) {
	for (int i = 0; i <= n; i++) {
		g[i].clear();
		par[i] = -1;
		vis[i] = false;
		lvis[i] = false;
		cyc[i] = false;
	}
	loop = -1;
	lend = -1;
}

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
	int n;
	cin >> n;
	allc(n);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	int curr = loop;
	vector<int> v;
	while (!lvis[curr] && curr != par[lend]) {
		v.push_back(curr);
		lvis[curr] = true;
		curr = par[curr];
	}
	for (int i : v) {cyc[i] = true;}
	DSU dsu(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j : g[i]) {
			if (!cyc[i] || !cyc[j]) {
				dsu.unite(i, j);
			}
		}
	}
	long long res = (long long)(n) * (n - 1);
	for (int i = 1; i <= n; i++) {
		if (dsu.get(i) == i) {
			res -= ((long long)(dsu.size(i)) * (dsu.size(i) - 1)) / 2;
		}
	}
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
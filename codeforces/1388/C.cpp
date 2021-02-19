// Problem: C. Uncle Bogdan and Country Happiness
// Contest: Codeforces - Codeforces Round #660 (Div. 2)
// URL: https://codeforces.com/contest/1388/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

vector<int> g[MAX], dg[MAX];
vector<long> p(MAX), h(MAX), sz(MAX), kannawoah(MAX), sadge(MAX);
vector<bool> vis(MAX);
bool fail;

void dfs(int v) {
	vis[v] = true;
	for (int i : g[v]) {
		if (!vis[i]) {
			dg[v].push_back(i);
			dfs(i);
		}
	}
}

long sum(int v) {
	long res = p[v];
	if (dg[v].empty()) {
		sz[v] = res;
		return res;
	}
	for (int i : dg[v]) {
		res += sum(i);
	}
	sz[v] = res;
	return res;
} 

void dgs(int v) {
	long sum = 0;
	for (int i : dg[v]) {
		sum += kannawoah[i];
	}
	if (sum > kannawoah[v]) {
		fail = true;
	}
	for (int i : dg[v]) {
		dgs(i);
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	p.clear();
	h.clear();
	for (int i = 0; i <= n + 7; i++) {
		g[i].clear();
		dg[i].clear();
	}
	fill(vis.begin(), vis.end(), false);
	sz.clear();
	kannawoah.clear();
	sadge.clear();
	fail = false;
	
	p.push_back(0);
	for (int i = 1; i <= n; i++) {
		long v;
		cin >> v;
		p.push_back(v);
	}
	h.push_back(0);
	for (int i = 1; i <= n; i++) {
		long v;
		cin >> v;
		h.push_back(v);
	}
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(1);
	sum(1);
	// for (int i = 1; i <= n; i++) {cout << sz[i] << ' ';} cout << endl;
	for (int i = 1; i <= n; i++) {
		if ((sz[i] + h[i]) % 2 != 0) {
			cout << "NO" << endl;
			return;
		}
		else {
			long happy = (sz[i] + h[i]) / 2, sad = sz[i] - happy;
			kannawoah[i] = happy;
			sadge[i] = sad;
			// cout << i << " " << happy << " " << sad << " " << sz[i] << endl;
			if (happy < 0 || sad < 0 || happy > sz[i] || sad > sz[i]) {cout << "NO" << endl; return;}
		}
	}
	// for (int i = 1; i <= n; i++) {cout << sz[i] << ' ';} cout << endl;
	dgs(1);
	cout << (fail ? "NO" : "YES") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
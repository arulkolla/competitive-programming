#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	set<int> g[n + 7];
	bool good[n + 7];
	for (int i = 0; i < n + 7; i++) {
		good[i] = false;
	}
	int goodcnt = 0;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	for (int i = 1; i <= n; i++) {
		if (g[i].empty() || *g[i].rbegin() < i) {good[i] = true; goodcnt++;}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int u, v;
			cin >> u >> v;
			g[u].insert(v);
			g[v].insert(u);
			bool ubef = good[u], vbef = good[v];
			if (g[u].empty() || *g[u].rbegin() < u) {good[u] = true;}
			else {good[u] = false;}
			if (ubef && !good[u]) {goodcnt--;}
			else if (!ubef && good[u]) {goodcnt++;}
			if (g[v].empty() || *g[v].rbegin() < v) {good[v] = true;}
			else {good[v] = false;}
			if (vbef && !good[v]) {goodcnt--;}
			else if (!vbef && good[v]) {goodcnt++;}
		}
		else if (type == 2) {
			int u, v;
			cin >> u >> v;
			g[u].erase(v);
			g[v].erase(u);
			bool ubef = good[u], vbef = good[v];
			if (g[u].empty() || *g[u].rbegin() < u) {good[u] = true;}
			else {good[u] = false;}
			if (ubef && !good[u]) {goodcnt--;}
			else if (!ubef && good[u]) {goodcnt++;}
			if (g[v].empty() || *g[v].rbegin() < v) {good[v] = true;}
			else {good[v] = false;}
			if (vbef && !good[v]) {goodcnt--;}
			else if (!vbef && good[v]) {goodcnt++;}
		}
		else {
			cout << goodcnt << '\n';
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
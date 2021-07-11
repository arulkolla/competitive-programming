#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

vector<int> g[MAX], gr[MAX];
int n, m;
int d[MAX] = {}, vis[MAX] = {}, cnt[MAX] = {};
int ps;
int path[MAX];

void solve() {
	cin >> n >> m;
	int v1, v2;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		gr[v2].push_back(v1);
	}
	cin >> ps;
	for (int i = 0; i < ps; i++) {
		cin >> path[i];
	}
	queue<int> q;
	q.push(path[ps - 1]);
	vis[path[ps - 1]] = true;
	d[path[ps - 1]] = 0;
	while (!q.empty()) {
		int v = q.front(); 
		q.pop();
		for (int u : gr[v]) {
			if (!vis[u]) {
				vis[u] = true;
				q.push(u);
				d[u] = d[v] + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cnt[d[i]]++;
	}
	int mn = 0, mx = 0;
	for (int i = 1; i < ps; i++) {
		if (d[path[i - 1]] - d[path[i]] != 1) {mn++;}
	}
	for (int i = 1; i < ps; i++) {
		if (d[path[i - 1]] - d[path[i]] != 1) {mx++;}
		else {
			for (int j : g[path[i - 1]]) {
				if (j != path[i] && d[j] == d[path[i]]) {mx++; break;}
			}
		}
	}
	cout << mn << ' ' << mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
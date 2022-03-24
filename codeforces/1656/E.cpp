#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	vector<int> g[n + 7];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bool vis[n + 7];
	int color[n + 7];
	for (int i = 1; i <= n; i++) {vis[i] = false;}
	queue<int> q;
	q.push(1);
	vis[1] = true;
	color[1] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : g[v]) {
	        if (!vis[u]) {
	            vis[u] = true;
	            q.push(u);
	            color[u] = color[v] * -1;
	        }
	    }
	}
	for (int i = 1; i <= n; i++) {
		cout << color[i] * (int)g[i].size() << ' ';
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
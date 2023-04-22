#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	int color[n + 7];
	vector<int> g[n + 7];
	vector<vector<int> > needy;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		color[i] = 2;
	}
	int k;
	cin >> k;
	for (int it = 0; it < k; it++) {
		int p, d;
		cin >> p >> d;
		queue<int> q;
		bool vis[n + 7];
		int dist[n + 7];
		for (int i = 1; i <= n; i++) {
			vis[i] = false;
			dist[i] = 0;
		}
		q.push(p);
		vis[p] = true;
		vector<int> nows;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			if (dist[x] < d) {color[x] = 0;}
			else if (dist[x] == d) {nows.push_back(x);}
			for (int y : g[x]) {
				if (!vis[y]) {
					dist[y] = dist[x] + 1;
					vis[y] = true;
					q.push(y);
				}
			}
		}
		needy.push_back(nows);
	}
	bool ok = true;
	for (auto vs : needy) {
		bool hit = false;
		for (int i : vs) {
			if (color[i] != 0) {
				color[i] = 1;
				hit = true;
			}
		}
		if (!hit) {ok = false;}
	}
	if (ok) {
		cout << "Yes\n";
		for (int i = 1; i <= n; i++) {
			cout << (color[i] > 0);
		}
		cout << '\n';
	}
	else {
		cout << "No\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	solve();
}
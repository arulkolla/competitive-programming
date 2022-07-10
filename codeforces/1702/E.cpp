#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	vector<int> g[n + 1];
	for (int i = 0; i < n; i++)	 {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (g[i].size() > 2) {cout << "NO\n"; return;}
	}
	vector<int> col(n + 1, -1);
	bool ok = true;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (col[i] == -1) {
			q.push(i);
			col[i] = 0;
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				for (int u : g[v]) {
					if (col[u] == -1) {col[u] = col[v] ^ 1; q.push(u);}
					else {ok &= (col[u] != col[v]);}
				}
			}
		}
	}
	cout << (ok ? "YES\n" : "NO\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
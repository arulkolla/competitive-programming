#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int n, m;
vector<pair<int, int> > g[MAX];
vector<int> dag[MAX];

vector<bool> visited;
vector<int> ans;

vector<int> color;
bool acyclic = true;

void dcolor(int v) {
    color[v] = 1;
    for (int u : dag[v])
        if (color[u] == 0) {
        	dcolor(u);
        }
        else if (color[u] == 1) {
        	acyclic = false;
        }
    color[v] = 2;
}

void dfs(int v) {
    visited[v] = true;
    for (int u : dag[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n + 7, false);
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int type;
		cin >> type;
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v, type);
		g[v].emplace_back(u, type);
	}
	vector<int> side(n + 7, -1);
	bool is_bipartite = true;
	queue<int> q;
	for (int st = 1; st <= n; ++st) {
	    if (side[st] == -1) {
	        q.push(st);
	        side[st] = 0;
	        while (!q.empty()) {
	            int v = q.front();
	            q.pop();
	            // cout << v << ' ';
	            for (auto edge : g[v]) {
	            	int u = edge.first;
	                if (side[u] == -1) {
	                    side[u] = side[v] ^ 1;
	                    q.push(u);
	                    // cout << u << " pushed\n";
	                } else {
	                    is_bipartite &= side[u] != side[v];
	                }
	            }
	        }
	    }
	}
	// for (int i = 1; i <= n; i++) {
		// cout << "val: " << i << ' ' << side[i] << '\n';
	// }
	if (!is_bipartite) {cout << "NO"; return;}
	for (int v = 1; v <= n; v++) {
		for (auto edge : g[v]) {
			if (edge.second == 1) {
				if (side[v] == 0) {
					dag[v].push_back(edge.first);
				}
				else {
					dag[edge.first].push_back(v);
				}
			}
			else {
				if (side[v] == 1) {
					dag[v].push_back(edge.first);
				}
				else {
					dag[edge.first].push_back(v);
				}
			}
		}
	}
	
	color.assign(n + 7, 0);
	for (int i = 1; i <= n; i++) {
		if (color[i] == 0) {
			dcolor(i);
		}
	}
	if (!acyclic) {cout << "NO"; return;}
	
	topological_sort();
	reverse(ans.begin(), ans.end());
	
	pair<int, int> rnd;
	int dir;
	for (int i = 1; i <= n; i++) {
		if (!g[i].empty()) {
			rnd = make_pair(i, g[i][0].first);
			dir = g[i][0].second;
			break;
		}
	}
	int pos[n + 7];
	for (int i = 1; i <= n; i++) {
		pos[ans[i - 1]] = i - 1;
	}
	bool Lis0;
	if (pos[rnd.first] < pos[rnd.second]) {
		if (dir == 1) {
			Lis0 = false;
		}
		else {
			Lis0 = true;
		}
	}
	else {
		if (dir == 1) {
			Lis0 = true;
		}
		else {
			Lis0 = false;
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		cout << (side[i] ^ !Lis0 ? 'L' : 'R') << ' ' << pos[i] << '\n';
	}
	
	// for (int i : ans) {
		// cout << i << ' ' << side[i] << '\n';
	// }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
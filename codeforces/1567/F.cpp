#include <bits/stdc++.h>

using namespace std;

const int MAX = 507;

char grid[MAX][MAX] = {};
bool vis[MAX][MAX] = {};
int val[MAX][MAX] = {}, res[MAX][MAX] = {}, color[MAX * MAX] = {};
set<int> graph[MAX * MAX] = {};
int ind = 0;

void dfs(int x, int y) {
    vis[x][y] = true;
    vector<pair<int, int> > v;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
        	v.emplace_back(x + i, y + j);
        }
    }
    for (auto p : v) {
        if (!vis[p.first][p.second] && grid[p.first][p.second] == '.') {
            val[p.first][p.second] = ind;
            dfs(p.first, p.second);
        }
    }
}

int flip(int x) {
    return (x == 1 ? 4 : 1);
}

void solve() {
	// take input
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (i == 0 || j == 0 || i == n + 1 || j == m + 1) {grid[i][j] = '!';}
            else {cin >> grid[i][j];}
        }
    }
    // check that all marked cells have proper degree
    for (int i = 2; i <= n - 1; i++) {
        for (int j = 2; j <= m - 1; j++) {
            int cnt = (grid[i - 1][j] == '.') + (grid[i + 1][j] == '.') + (grid[i][j - 1] == '.') + (grid[i][j + 1] == '.');
            if (grid[i][j] == 'X' && cnt % 2 == 1) {cout << "NO" << endl; return;}
        }
    }
    // find connected components
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                ind++;
                val[i][j] = ind;
                dfs(i, j);
            }
        }
    }
    // build graph of connected components
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		if (grid[i][j] == 'X') {
    			bool horz = (grid[i][j - 1] == '.' && grid[i][j + 1] == '.');
    			bool vert = (grid[i - 1][j] == '.' && grid[i + 1][j] == '.');
    			if (horz && (val[i][j - 1] != val[i][j + 1])) {
    				graph[val[i][j - 1]].insert(val[i][j + 1]);
    				graph[val[i][j + 1]].insert(val[i][j - 1]);
    			}
    			if (vert && (val[i - 1][j] != val[i + 1][j])) {
    				graph[val[i - 1][j]].insert(val[i + 1][j]);
    				graph[val[i + 1][j]].insert(val[i - 1][j]);
    			}
    			
    		}
    	}
    }
    // make bipartite coloring of graph
    queue<int> q;
    for (int i = 1; i <= ind; i++) {
    	if (color[i] == 0) {
    		q.push(i);
    		color[i] = 1;
    		while (!q.empty()) {
    			int v = q.front();
    			q.pop();
    			for (int u : graph[v]) {
    				if (color[u] == 0) {color[u] = (color[v] ^ 3); q.push(u);}
    				else if (color[u] == color[v]) {cout << "NO" << endl; return;}
    			}
    		}
    	}
    }
    // flip each cell appropriately, column by column
    for (int j = 1; j <= m; j++) {
        int curr = (j % 2 ? 4 : 1);
        res[1][j] = curr;
        int prev = color[val[1][j]];
        for (int i = 2; i <= n; i++) {
            if (grid[i][j] == '.') {
                if (color[val[i][j]] != prev) {curr = flip(curr);}
                res[i][j] = curr;
                prev = color[val[i][j]];
            }
        }
    }
    // find values of marked cells
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 'X') {
                if (grid[i - 1][j] == '.') {res[i][j] += res[i - 1][j];}
                if (grid[i + 1][j] == '.') {res[i][j] += res[i + 1][j];}
                if (grid[i][j - 1] == '.') {res[i][j] += res[i][j - 1];}
                if (grid[i][j + 1] == '.') {res[i][j] += res[i][j + 1];}
            }
        }
    }
    // output the answer
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
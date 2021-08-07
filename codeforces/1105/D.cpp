#include <bits/stdc++.h>

using namespace std;

const int MAX = 1007;
const int MOD = 1000000007;

int n, m, p;
char g[MAX][MAX];
int dist[11][MAX][MAX];
bool vis[MAX][MAX];
queue<pair<int, int> > qu[11];

void solve() {
	int n, m, p;
	cin >> n >> m >> p;
	int s[p + 7];
	for (int i = 1; i <= p; i++) {
		cin >> s[i];
	}
	int res[p + 7];
	for (int i = 1; i <= p; i++) {
		res[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			vis[i][j] = false;
			if (g[i][j] != '.' && g[i][j] != '#') {
				qu[(int)g[i][j] - 48].push(make_pair(i, j));
				res[(int)g[i][j] - 48]++;
			}
		}
	}
	
	while (true) {
		bool ok = false;
		for (int pl = 1; pl <= p; pl++) {
			int curd = s[pl];
			for (int mv = 0; mv < curd; mv++) {
				if (qu[pl].empty()) {break;}
				ok = true;
				int rn = qu[pl].size();
				for (int _ = 0; _ < rn; _++) {
					pair<int, int> pc = qu[pl].front();
					qu[pl].pop();
					int i = pc.first, j = pc.second;
					if (i > 0) {
						if (g[i - 1][j] == '.' && !vis[i - 1][j]) {
							vis[i - 1][j] = true;
							g[i - 1][j] = (char)(48 + pl);
							res[pl]++;
							qu[pl].push(make_pair(i - 1, j));
						}
					}
					if (i < n - 1) {
						if (g[i + 1][j] == '.' && !vis[i + 1][j]) {
							vis[i + 1][j] = true;
							g[i + 1][j] = (char)(48 + pl);
							res[pl]++;
							qu[pl].push(make_pair(i + 1, j));
						}
					}
					if (j > 0) {
						if (g[i][j - 1] == '.' && !vis[i][j - 1]) {
							vis[i][j - 1] = true;
							g[i][j - 1] = (char)(48 + pl);
							res[pl]++;
							qu[pl].push(make_pair(i, j - 1));
						}
					}
					if (j < m - 1) {
						if (g[i][j + 1] == '.' && !vis[i][j + 1]) {
							vis[i][j + 1] = true;
							g[i][j + 1] = (char)(48 + pl);
							res[pl]++;
							qu[pl].push(make_pair(i, j + 1));
						}
					}
				}
			}
		}
		if (!ok) {break;}
	}
	// for (int i = 0; i < n; i++) {
		// for (int j = 0; j < m; j++) {
			// cout << g[i][j];
		// }
		// cout << endl;
	// }
	for (int i = 1; i <= p; i++) {
		cout << res[i] << ' ';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
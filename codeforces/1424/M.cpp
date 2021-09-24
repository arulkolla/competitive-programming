#include <bits/stdc++.h>

using namespace std;

const int MAX = 27;
const int MOD = 1000000007;

vector<int> g[MAX];
bool vis[MAX] = {};
int color[MAX] = {};
vector<int> top;
bool bad = false;

void dfs(int v) {
    color[v] = 1;
    for (int u : g[v]) {
    	if (color[u] == 0) {dfs(u);}
    	if (color[u] == 1) {bad = true;}
    }
    color[v] = 2;
    top.push_back(v);
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<string> v;
	vector<vector<string> > pg(n);
	string tmp;
	int ptmp;
	bool seen[MAX] = {};
	// stupid processing
	for (int i = 0; i < n; i++) {
		cin >> ptmp;
		for (int j = 0; j < k; j++) {
			cin >> tmp;
			pg[ptmp].push_back(tmp);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			v.push_back(pg[i][j]);
		}
	}
	// ok here's the problem
	for (string s : v) {
		for (char c : s) {
			seen[(int)c - (int)'a'] = true;
		}
	}
	vector<int> in;
	for (int i = 0; i < MAX; i++) {
		if (seen[i]) {in.push_back(i);}
	}
	n *= k;
	for (int i = 1; i < n; i++) {
		bool done = false;
		for (int j = 0; j < min(v[i - 1].size(), v[i].size()); j++) {
			if (!done && v[i - 1][j] != v[i][j]) {
				g[(int)v[i - 1][j] - (int)'a'].push_back((int)v[i][j] - (int)'a');
				done = true;
			}
		}
		if (!done && v[i - 1].size() > v[i].size()) {cout << "IMPOSSIBLE"; return;}
	}
	for (int i : in) {
		if (color[i] == 0) {dfs(i);}
	}
	if (bad) {cout << "IMPOSSIBLE"; return;}
	reverse(top.begin(), top.end());
	for (int i : top) {
		cout << (char)(i + (int)'a');
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
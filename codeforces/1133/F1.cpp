
// Problem: F1. Spanning Tree with Maximum Degree
// Contest: Codeforces - Codeforces Round #544 (Div. 3)
// URL: https://codeforces.com/contest/1133/problem/F1
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int v, e;
vector<int> g[MAX];
bool vis[MAX];
queue<int> q;

void use(int v) {
	q.push(v);
	vis[v] = true;
}

void solve() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int mx = 0, mxVal;
	for (int i = 1; i <= v; i++) {
		if (g[i].size() > mx) {
			mx = g[i].size();
			mxVal = i;
		}
	}
	use(mxVal);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i : g[now]) {
			if (!vis[i]) {
				cout << now << " " << i << endl;
				use(i);
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
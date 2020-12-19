
// Problem: D. Swaps in Permutation
// Contest: Codeforces - Educational Codeforces Round 14
// URL: https://codeforces.com/contest/691/problem/D
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000007;
const int MOD = 1000000007;

vector<int> g[MAX];
bool vis[MAX];
int v, e;
vector<int> curr;

void dfs(int v) { 
	curr.push_back(v);
	vis[v] = true;
	for (int i : g[v]) {
		if (!vis[i]) {
			dfs(i);
		}
	}
}

void solve() {
	cin >> v >> e;
	int a[v + 7];
	for (int i = 1; i <= v; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= e; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 1; i <= v; i++) {
		if (!vis[i]) {
			curr.clear();
			dfs(i);
			vector<int> now;
			for (int j : curr) {
				now.push_back(a[j]);
			}
			sort(now.begin(), now.end(), greater<int>());
			sort(curr.begin(), curr.end());
			for (int j = 0; j < curr.size(); j++) {
				a[curr[j]] = now[j];
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		cout << a[i] << " ";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
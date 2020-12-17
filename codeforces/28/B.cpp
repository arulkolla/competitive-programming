
// Problem: B. pSort
// Contest: Codeforces - Codeforces Beta Round #28 (Codeforces format)
// URL: https://codeforces.com/problemset/problem/28/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 107;
const int MOD = 1000000007;

int n;
vector<int> g[MAX];
bool vis[MAX];
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
	cin >> n;
	int a[MAX];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (1 <= i + x && i + x <= n) {
			g[i].push_back(i + x);
			g[i + x].push_back(i);
		}
		if (1 <= i - x && i - x <= n) {
			g[i].push_back(i - x);
			g[i - x].push_back(i);
		}
	}
	bool ok = true;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			curr.clear();
			dfs(i);
			vector<int> now;
			for (int j : curr) {
				now.push_back(a[j]);
			}
			sort(now.begin(), now.end());
			sort(curr.begin(), curr.end());
			for (int j = 0; j < curr.size(); j++) {
				if (curr[j] != now[j]) {ok = false;}
			}
		}
	}
	cout << (ok ? "YES" : "NO");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
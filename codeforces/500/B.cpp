
// Problem: B. New Year Permutation
// Contest: Codeforces - Good Bye 2014
// URL: https://codeforces.com/problemset/problem/500/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 307;
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
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= n; j++) {
			if (s[j - 1] == '1') {g[i].push_back(j);}
		}
	}
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
				a[curr[j]] = now[j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
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
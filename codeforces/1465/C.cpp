
// Problem: C. Peaceful Rooks
// Contest: Codeforces - Codeforces Round #692 (Div. 2, based on Technocup 2021 Elimination Round 3)
// URL: https://codeforces.com/contest/1465/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100007;
const int MOD = 1000000007;

vector<int> g[MAX];
bool vis[MAX], mp[MAX];
vector<int> curr;
bool cyc = false;
int cnt = 0;
int n, m;

void dfs(int v) {
	vis[v] = true;
	cnt++;
	curr.push_back(v);
	for (int i : g[v]) {
		if (!vis[i]) {
			dfs(i);
		}
		else {
			cyc = true;
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {g[i].clear();}
	for (int i = 0; i <= n; i++) {vis[i] = false; mp[i] = false;}
	curr.clear();
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		if (x != y) {mp[y] = true;}
	}
	int res = m;
	for (int i = 1; i <= n; i++) {
		if (!g[i].empty() && !vis[i]) {
			curr.clear();
			cyc = false;
			cnt = 0;
			dfs(i);
			if (!cyc && mp[i]) {
				//we started in the middle, ignore
				for (int j : curr) {
					vis[j] = false;
				}
			}
			else {
				if (cyc && cnt != 1) {
					res++;
				}
				else if (cyc && cnt == 1) {
					res--;
				}
			}
		}
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
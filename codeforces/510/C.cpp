
// Problem: C. Fox And Names
// Contest: Codeforces - Codeforces Round #290 (Div. 2)
// URL: https://codeforces.com/contest/510/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

vector<int> g[27];
bool vis1[27], vis2[27];
string res;
bool bad = false;

void dfs(int v) {
	if (vis2[v]) {return;}
	if (vis1[v]) {bad = true; return;}
	vis1[v] = true;
	for (int i : g[v]) { 
		dfs(i);
	}
	vis1[v] = false;
	vis2[v] = true;
	res += ('a' + v);
}

void solve() {
	int n;
	cin >> n;
	string a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			bool done = false;
			for (int k = 0; k < min(a[i].size(), a[j].size()); k++) {
				int in = a[i][k] - 'a', jn = a[j][k] - 'a';
				if (in != jn) {
					g[in].push_back(jn);
					done = true;
					break;
				}
			}
			if (!done) {
				if (a[i].size() > a[j].size()) {bad = true;}
			}
		}
	}
	
	for (int i = 0; i < 26; i++) {
		if (!vis1[i]) {
			dfs(i);
		}	
	}
	reverse(res.begin(), res.end());
	if (bad) {cout << "Impossible"; return;}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
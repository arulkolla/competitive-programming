
// Problem: C. Perfect Keyboard
// Contest: Codeforces - Educational Codeforces Round 82 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1303/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 37;
const int MOD = 1000000007;

set<int> g[MAX];
bool vis[MAX];
string res;

void dfs(int v) {
	res += ('a' + (v - 1));
	vis[v] = true;
	for (int i : g[v]) {
		if (!vis[i]) {
			dfs(i);
		}
	}
}

void clear() {
	for (int i = 0; i < MAX; i++) {g[i].clear(); vis[i] = false;}
	res = "";
}

void solve() {
	clear();
	string s;
	cin >> s;
	bool used[MAX] = {};
	set<int> use;
	for (int i = 0; i < s.length() - 1; i++) {
		int v1 = s[i] - 'a' + 1, v2 = s[i + 1] - 'a' + 1;
		g[v1].insert(v2);
		g[v2].insert(v1);
		used[v1] = true, used[v2] = true;
		use.insert(v1);
		use.insert(v2);
	}
	bool ok = true;
	int one = 0, two = 0;
	int oneOne;
	for (int i : use) {
		if (g[i].size() == 1) {one++; oneOne = i;}
		else if (g[i].size() == 2) {two++;}
		else if (!g[i].empty()) {ok = false;}
	}
	if (one != 2 || two != use.size() - 2) {ok = false;}
	if (use.size() == 0) {cout << "YES\nqwertyuioplkjhgfdsazxcvbnm" << endl; return;}
	if (!ok) {cout << "NO" << endl; return;}
	cout << "YES" << endl;
	dfs(oneOne);
	cout << res;
	for (int i = 1; i <= 26; i++) {
		if (!used[i]) {
			char now = 'a' + (i - 1);
			cout << now;
		}
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
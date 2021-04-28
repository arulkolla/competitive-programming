#include <bits/stdc++.h>

using namespace std;

const int MAX = 100007;
const int MOD = 1000000007;

vector<int> g[MAX], children[MAX];
bool vis[MAX];
int n;

void dfs(int v) {
	vis[v] = true;
	for (int i : g[v]) {
		if (!vis[i]) {
			children[v].push_back(i);
		}
	}
	for (int i : g[v]) {
		if (!vis[i]) {
			dfs(i);
		}
	}
}

long double f(int i) {
	if (children[i].empty()) {return (long double)0;}
	long double res = 0;
	for (int j : children[i]) {
		res += (f(j) + 1);
	}
	res /= children[i].size();
	return res;
}

void solve() {
	int n;
	cin >> n;
	int e1, e2;
	for (int i = 0; i < n - 1; i++) {
		cin >> e1 >> e2;
		g[e1].push_back(e2);
		g[e2].push_back(e1);
	}
	dfs(1);
	cout << fixed << setprecision(17) << f(1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
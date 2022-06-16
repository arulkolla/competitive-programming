#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

vector<int> g[MAX];
int par[MAX];
long long dp[MAX];
pair<long long, long long> range[MAX];

long long f(int v) {
	if (dp[v] != LLONG_MAX) {return dp[v];}
	if (g[v].empty()) {dp[v] = 1; return dp[v];}
	long long l = 0, r = 0, tot = 0;
	for (int w : g[v]) {
		tot += f(w);
		l += range[w].first; r += range[w].second;
	}
	if (r < range[v].first) {tot++;}
	else {range[v].second = min(r, range[v].second);}
	dp[v] = tot;
	return tot;
}

void allc(int n) {
	for (int i = 0; i <= n; i++) {
		g[i].clear();
		par[i] = -1;
		dp[i] = LLONG_MAX;
		range[i] = make_pair(-1, -1);
	}
}

void solve() {
	int n;
	cin >> n;
	allc(n);
	for (int i = 2; i <= n; i++) {
		cin >> par[i];
		g[par[i]].push_back(i);
	}
	for (int i  = 1; i <= n; i++) {
		cin >> range[i].first >> range[i].second;
	}
	cout << f(1) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
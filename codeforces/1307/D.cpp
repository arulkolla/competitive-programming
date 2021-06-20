#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int a[k + 7];
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	vector<int> g[n + 7];
	int e1, e2;
	for (int i = 0; i < m; i++) {
		cin >> e1 >> e2;
		g[e1].push_back(e2);
		g[e2].push_back(e1);
	}
	bool vis[n + 7];
	int dist1[n + 7], distn[n + 7];
	for (int i = 1; i <= n; i++) {
		vis[i] = false;
		dist1[i] = 0;
		distn[i] = 0;
	}
	queue<int> q;
	q.push(1);
	vis[1] = true;
	int v;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int i : g[v]) {
			if (!vis[i]) {
				vis[i] = true;
				q.push(i);
				dist1[i] = dist1[v] + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		vis[i] = false;
	}
	q.push(n);
	vis[n] = true;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int i : g[v]) {
			if (!vis[i]) {
				vis[i] = true;
				q.push(i);
				distn[i] = distn[v] + 1;
			}
		}
	}
	pair<int, int> val[k + 7];
	for (int i = 0; i < k; i++) {
		val[i] = make_pair(dist1[a[i]] - distn[a[i]], a[i]);
	}
	sort(val, val + k);
	int res = 0, curr = -MOD;
	for (int i = 0; i < k; i++) {
		res = max(res, curr + distn[val[i].second]);
		curr = max(curr, dist1[val[i].second]);
	}
	cout << min(dist1[n], 1 + res) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
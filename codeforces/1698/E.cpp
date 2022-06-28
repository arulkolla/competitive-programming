#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 998244353;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return (a.second < b.second);
}

void solve() {
	int n, s;
	cin >> n >> s;
	pair<int, int> a[n + 1];
	bool vis[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		vis[i] = false;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].second;
		if (a[i].second != -1) {
			vis[a[i].second] = true;
		}
	}
	vector<int> missing;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {missing.push_back(i);}
	}
	sort(a + 1, a + n + 1, cmp);
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i].second != -1) {
			mx = max(mx, a[i].first - a[i].second);
		}
	}
	if (mx > s) {cout << 0 << '\n'; return;}
	vector<int> cnts;
	for (int i = 1; i <= n; i++) {
		if (a[i].second == -1) {
			cnts.push_back(missing.end() - lower_bound(missing.begin(), missing.end(), a[i].first - s));
		}
	}
	sort(cnts.begin(), cnts.end());
	long long res = 1;
	for (int i = 0; i < cnts.size(); i++) {
		res = (res * (cnts[i] - i)) % MOD;
	}
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
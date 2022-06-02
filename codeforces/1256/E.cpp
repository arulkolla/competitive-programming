#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int n, dp[MAX];
pair<int, int> a[MAX];

int f(int k) {
	// solve for [0..k]
	if (k < 3 || dp[k] != MOD) {return dp[k];}
	for (int off = 3; off <= 5; off++) {
		dp[k] = min(dp[k], f(k - off) + a[k].first - a[k - off + 1].first);
	}
	return dp[k];
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = MOD;
	}
	cout << f(n) << ' ';
	int curr = n;
	vector<int> v;
	while (curr > 0) {
		for (int off = 3; off <= 5; off++) {
			if (dp[curr] == dp[curr - off] + a[curr].first - a[curr - off + 1].first) {
				v.push_back(off);
				curr -= off;
				break;
			}
		}
	}
	cout << v.size() << '\n';
	reverse(v.begin(), v.end());
	int color[n + 1], pos = 1;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i]; j++) {
			color[a[pos].second] = i + 1;
			pos++;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << color[i] << ' ';
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
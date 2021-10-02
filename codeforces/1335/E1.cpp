#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int dp[n + 7][37];
	for (int i = 0; i < n + 5; i++) {
		for (int j = 0; j < 35; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 26; j++) {
			dp[i][j] += dp[i-1][j] + (a[i] == j);
		}
			
	}
	int res = -MOD;
	for (int i = 1; i <= 26; i++) {
		res = max(res, dp[n][i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int x = 0, y = 0;
			for (int k = 1; k <= 26; k++) {
				x = max(x, 2 * min(dp[i - 1][k], dp[n][k] - dp[j][k]));
				y = max(y, dp[j][k] - dp[i - 1][k]);
			}
			res = max(res, x + y);
		}
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
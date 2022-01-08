#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int dp[n + 7][3], a[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 3; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
		if (a[i] & 1) {
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
		}
		else {
			dp[i][1] = MOD;
		}
		if (a[i] & 2) {
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
		}
		else {
			dp[i][2] = MOD;
		}
	}
	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
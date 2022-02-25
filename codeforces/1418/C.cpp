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
	a[0] = 0;
	int dp[n + 7][2]; // dp[index][0 = friend, 1 = me]
	dp[1][0] = a[1]; dp[1][1] = MOD;
	dp[2][0] = a[1] + a[2]; dp[2][1] = dp[1][0];
	for (int i = 3; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1] + a[i], dp[i - 2][1] + a[i - 1] + a[i]);
		dp[i][1] = min(dp[i - 1][0], dp[i - 2][0]);
	}
	cout << min(dp[n][0], dp[n][1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
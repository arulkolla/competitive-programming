#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int dp[n + 7][k + 7], curr = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
        while (a[i] - a[curr] > 5) {curr++;}
        for (int j = 1; j <= k; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[curr - 1][j - 1] + i - curr + 1);
        }
	}
	cout << dp[n][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
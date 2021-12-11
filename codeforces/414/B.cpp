#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	k--;
	int dp[n + 7][k + 7];
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (int i = 0; i <= k; i++) {
		dp[1][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = 0;
			for (int d = 1; d * d <= i; d++) {
				if (i % d == 0) {
					dp[i][j] = (dp[i][j] + dp[d][j - 1]) % MOD;
					if (i / d != d) {
						dp[i][j] = (dp[i][j] + dp[i / d][j - 1]) % MOD;
					}
				}
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = (res + dp[i][k]) % MOD;
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}

/*
dp

some divisibilty sequence can be made by 
adding some number to a previous divisibility sequence
so let M be maximum of divisibility
then all mulitples of M get added k-1

f(n, k) = sum f(d, k - 1) where d is divisor of n
and then prefix sums?
*/

/*

n k -->

V

n=1: 1 1 1
n=2: 1 2 3
n=3: 1 2 3
seems fine

*/
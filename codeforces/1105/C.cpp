#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long add(long long a, long long b) {
	return (a + b) % MOD;
}

long long add(long long a, long long b, long long c) {
	return add(add(a, b), c);
}

long long mul(long long a, long long b) {
	return (a * 1ll * b) % MOD;
}

void solve() {
	int n;
	long long a, b;
	cin >> n >> a >> b;
	long long c0 = (b / 3) - (a / 3), c1 = ((b + 2) / 3) - ((a + 2) / 3), c2 = ((b + 1) / 3) - ((a + 1) / 3);
	if (a % 3 == 0) {c0++;}
	else if (a % 3 == 1) {c1++;}
	else {c2++;}
	// cout << c0 << ' ' << c1 << ' ' << c2 << endl;
	long long dp[n + 7][4];
	dp[1][0] = c0; dp[1][1] = c1; dp[1][2] = c2;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = add(mul(dp[i - 1][1], c2), mul(dp[i - 1][2], c1), mul(dp[i - 1][0], c0));
		dp[i][1] = add(mul(dp[i - 1][2], c2), mul(dp[i - 1][0], c1), mul(dp[i - 1][1], c0));
		dp[i][2] = add(mul(dp[i - 1][0], c2), mul(dp[i - 1][1], c1), mul(dp[i - 1][2], c0));
	}
	cout << dp[n][0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
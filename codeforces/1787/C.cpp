#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long s;
	cin >> n >> s;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<long long> v;
	v.push_back(a[0]);
	for (int i = 1; i < n - 1; i++) {
		if (a[i] < s) {
			v.push_back(a[i]);
			v.push_back(0);
		}
		else {
			v.push_back(s);
			v.push_back(a[i] - s);
		}
	}
	v.push_back(a[n - 1]);
	long long dp[n][2];
	dp[1][0] = a[0] * v[1];
	dp[1][1] = a[0] * v[2];
	for (int i = 2; i < n - 1; i++) {
		dp[i][0] = min(dp[i - 1][0] + v[2 * i - 1] * v[2 * i - 2], dp[i - 1][1] + v[2 * i - 1] * v[2 * i - 3]);
		dp[i][1] = min(dp[i - 1][0] + v[2 * i] * v[2 * i - 2], dp[i - 1][1] + v[2 * i] * v[2 * i - 3]);
	}
	cout << min(dp[n - 2][0] + v[2 * n - 4] * a[n - 1], dp[n - 2][1] + v[2 * n - 5] * a[n - 1]) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
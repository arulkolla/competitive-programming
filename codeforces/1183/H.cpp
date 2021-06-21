#include <bits/stdc++.h>

using namespace std;

const int MAX = 107;
const int MOD = 1000000007;

long long dp[MAX][MAX] = {}; // dp[i][j] is # of substr of 1..i of length j

void solve() {
	int n;
	long long k;
	cin >> n >> k;
	string s;
	cin >> s;
	s = '!' + s;
	set<char> chars;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		dp[i][1] = dp[i - 1][1];
		if (chars.find(s[i]) == chars.end()) {dp[i][1]++; chars.insert(s[i]);}
	}
	for (int l = 2; l <= n; l++) {
		for (int i = l; i <= n; i++) {
			dp[i][l] = dp[i - 1][l] + dp[i - 1][l - 1];
			for (int j = i - 1; j >= 1; j--) {
				if (s[i] == s[j]) {dp[i][l] -= dp[j - 1][l - 1]; break;}
			}
		}
	}
	long long res = 0;
	for (int i = n; i >= 0; i--) {
		if (k > dp[n][i]) {res += dp[n][i] * (n - i); k -= dp[n][i];}
		else {res += k * (n - i); k = 0; break;}
	}
	if (k > 0) {res = -1;}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
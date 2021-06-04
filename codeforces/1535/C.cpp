#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

#define wat(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int flip(int n) {
	if (n == 0) {return 1;}
	return 0;
}

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	long long dp[n + 7];
	dp[0] = 1;
	int curr = -1, qcount = 1, qs = 0;
	if (s[0] == '0') {curr = 1;}
	if (s[0] == '1') {curr = 0;}
	if (s[0] == '?') {qs++;}
	for (int i = 1; i < n; i++) {
		if (s[i - 1] == '?') {
			if (curr == -1) {
				if (s[i] == '0') {curr = 1;}
				if (s[i] == '1') {curr = 0;}
				dp[i] = dp[i - 1] + qcount + 1;
				qcount++;
			}
			else {
				if (s[i] == '0' + curr || s[i] == '?') {
					curr = flip(curr);
					dp[i] = dp[i - 1] + qcount + 1;
					qcount++;
				}
				else {
					// we lost
					dp[i] = dp[i - 1] + qs + 1;
					qcount = qs + 1; // check?
				}
			}
		}
		else if (s[i - 1] == '0') {
			if (s[i] == '0') {
				// we can only do one
				dp[i] = dp[i - 1] + 1;
				curr = 1;
				qcount = 1;
			}
			else {
				// we'll continue
				dp[i] = dp[i - 1] + qcount + 1;
				curr = 0;
				qcount++;
			}
		}
		else {
			if (s[i] == '1') {
				// we can only do one
				dp[i] = dp[i - 1] + 1;
				curr = 0;
				qcount = 1;
			}
			else {
				// we'll continue
				dp[i] = dp[i - 1] + qcount + 1;
				curr = 1;
				qcount++;
			}
		}
		if (s[i] == '?') {qs++;}
		else {qs = 0;}
		// cout << wat(i) << wat(s[i]) << wat(dp[i]) << wat(curr) << wat(qcount) << wat(qs) << endl;
	}
	cout << dp[n - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
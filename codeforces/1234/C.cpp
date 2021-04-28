#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	bool a[n + 7][2];
	char c;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		if (c == '1' || c == '2') {a[i][0] = false;}
		else {a[i][0] = true;}
	}
	for (int i = 1; i <= n; i++) {
		cin >> c;
		if (c == '1' || c == '2') {a[i][1] = false;}
		else {a[i][1] = true;}
	}
	bool dp[n + 7];
	dp[0] = true;
	for (int i = 1; i <= n; i++) {
		if (a[i][0] && a[i][1]) {dp[i] = !dp[i - 1];}
		else if (dp[i - 1]) {
			if (!a[i][0]) {dp[i] = dp[i - 1];}
			else {cout << "NO" << endl; return;}
		}
		else {
			if (!a[i][1]) {dp[i] = dp[i - 1];}
			else {cout << "NO" << endl; return;}
		}
	}
	cout << (dp[n] ? "NO" : "YES") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
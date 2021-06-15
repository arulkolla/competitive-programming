#include <bits/stdc++.h>

using namespace std;

const int MAX = 107;
const int MOD = 1000000007;

#define wat(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int n;
int a[MAX];
int dp[107][57][57][3];

int f(int pos, int r, int b, int after) {
	if (dp[pos][r][b][after] != -1) {return dp[pos][r][b][after];}
	// cout << wat(pos) << wat(r) << wat(b) << wat(after) << "started." << endl;
	if (pos == 1) {
		int res;
		if (r > 0 || a[pos] == 1) {
			if (after == 2) {res = 1;}
			else {res = 0;}
		}
		else if (b > 0 || a[pos] == 2) {
			if (after == 1) {res = 1;}
			else {res = 0;}
		}
		else {
			res = 0;
		}
		// cout << wat(pos) << wat(r) << wat(b) << wat(after) << "returns: ";
		// cout << wat(res) << endl;
		return res;
	}
	int mn = MOD;
	if (a[pos] != 0) {
		if (a[pos] == 1) {
			// this is red
			int res = f(pos - 1, r, b, 1);
			if (after == 2) {res++;}
			mn = min(mn, res);
		}
		else {
			// this is blue
			int res = f(pos - 1, r, b, 2);
			if (after == 1) {res++;}
			mn = min(mn, res);
		}
	}
	else {
		if (r > 0) {
			// test red
			int res = f(pos - 1, r - 1, b, 1);
			if (after == 2) {res++;}
			mn = min(mn, res);
		}
		if (b > 0) {
			// test blue
			int res = f(pos - 1, r, b - 1, 2);
			if (after == 1) {res++;}
			mn = min(mn, res);
		}
	}
	// cout << wat(pos) << wat(r) << wat(b) << wat(after) << "returns: ";
	// cout << wat(mn) << endl;
	dp[pos][r][b][after] = mn;
	return mn;
}

void solve() {
	for (int i = 0; i < 107; i++) {
		for (int j = 0; j < 57; j++) {
			for (int k = 0; k < 57; k++) {
				for (int l = 0; l < 3; l++) {
					dp[i][j][k][l] = -1;
				}
			}
		}
	}
	cin >> n;
	int reds = (n + 1) / 2, blues = n / 2;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 0) {
			if (a[i] % 2 == 1) {a[i] = 1; reds--;}
			else {a[i] = 2; blues--;}
		}
	}
	cout << f(n, reds, blues, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
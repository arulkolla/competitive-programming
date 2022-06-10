#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	char g[n + 1][m + 1];
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> g[i][j];
			if (g[i][j] == 'B') {v.emplace_back(i, j);}
		}
	}	
	int mns = MOD, mxs = -MOD, mnd = MOD, mxd = -MOD;
	for (auto p : v) {
		// cout << p.first << ',' << p.second << '\n';
		mns = min(mns, p.first + p.second);
		mxs = max(mxs, p.first + p.second);
		mnd = min(mnd, p.first - p.second);
		mxd = max(mxd, p.first - p.second);
	}
	int rs = mxs - mns, rd = mxd - mnd;
	// int s = min(rs, rd), b = max(rs, rd);
	// cout << mns << ' ' << mxs << ' ' << mnd << ' ' << mxd << '\n';
	// cout << rs << ' ' << rd << '\n';
	// cout << s << ' ' << b << ' ' << (b - s) / 2 << '\n';
	int d = max((rs + 1) / 2, (rd + 1) / 2);
	// if (s % 2 == 0 && b % 2 == 0 && ((b - s) / 2) % 2 == 1) {
		// d = b / 2 + 1;
	// }
	// else {
		// d = (b + 2) / 2;
		// cout << "b: " << b << ' ' << "d: " << d << '\n';
	// }
	// cout << d << '\n';
	for (int i = mxs - d; i <= mns + d; i++) {
		for (int j = mxd - d; j <= mnd + d; j++) {
			if ((i + j) % 2 == 0) {cout << (i + j) / 2 << ' ' << (i - j) / 2 << '\n'; return;}
		}
	}
	for (int i = mxs - d - 1; i <= mns + d + 1; i++) {
		for (int j = mxd - d - 1; j <= mnd + d + 1; j++) {
			if ((i + j) % 2 == 0) {cout << (i + j) / 2 << ' ' << (i - j) / 2 << '\n'; return;}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
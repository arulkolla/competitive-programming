#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	int a[n + 1][m + 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}	
	if ((n + m) % 2 == 0) {cout << "NO\n"; return;}
	int dpmin[n + 1][m + 1], dpmax[n + 1][m + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dpmin[i][j] = 0;
			dpmax[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j != 1) {
				dpmin[i][j] = dpmin[i][j - 1] + a[i][j];
				dpmax[i][j] = dpmax[i][j - 1] + a[i][j];
			}
			else if (i != 1 && j == 1) {
				dpmin[i][j] = dpmin[i - 1][j] + a[i][j];
				dpmax[i][j] = dpmax[i - 1][j] + a[i][j];
			}
			else {
				dpmin[i][j] = min(dpmin[i - 1][j], dpmin[i][j - 1]) + a[i][j];
				dpmax[i][j] = max(dpmax[i - 1][j], dpmax[i][j - 1]) + a[i][j];
			}
		}
	}	
	if (dpmin[n][m] <= 0 && 0 <= dpmax[n][m]) {cout << "YES\n";}
	else {cout << "NO\n";}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
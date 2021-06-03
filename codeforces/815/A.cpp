#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	int mn = MOD, row, col;
	int a[n + 7][m + 7];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] < mn) {
				mn = a[i][j];
				row = i;
				col = j;
			}
		}
	}
	vector<pair<string, int> > res;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] + mn != a[row][j] + a[i][col]) {
				cout << -1 << endl; return;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int pos = 0; pos < a[i][col] - mn; pos++) {
			res.emplace_back("row", i + 1);
		}
	}
	for (int j = 0; j < m; j++) {
		for (int pos = 0; pos < a[row][j] - mn; pos++) {
			res.emplace_back("col", j + 1);
		}
	}
	if (m <= n) {
		for (int pos = 0; pos < mn; pos++) {
			for (int i = 0; i < m; i++) {
				res.emplace_back("col", i + 1);
			}
		}
	}
	else {
		for (int pos = 0; pos < mn; pos++) {
			for (int i = 0; i < n; i++) {
				res.emplace_back("row", i + 1);
			}
		}
	}
	cout << res.size() << endl;
	for (auto i : res) {
		cout << i.first << ' ' << i.second << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
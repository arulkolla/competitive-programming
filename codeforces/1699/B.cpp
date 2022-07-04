#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	int a[n][m];
	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < m; j += 2) {
			if ((i/2 + j/2) % 2 == 0) {
				a[i][j] = 1;
				a[i + 1][j] = 0;
				a[i][j + 1] = 0;
				a[i + 1][j + 1] = 1;
			}
			else {
				a[i][j] = 0;
				a[i + 1][j] = 1;
				a[i][j + 1] = 1;
				a[i + 1][j + 1] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
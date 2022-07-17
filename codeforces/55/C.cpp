#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5 || x == n || x == n - 1 || x == n - 2 || x == n - 3 || x == n - 4) {
			cout << "YES";
			return;
		}
		if (y == 1 || y == 2 || y == 3 || y == 4 || y == 5 || y == m || y == m - 1 || y == m - 2 || y == m - 3 || y == m - 4) {
			cout << "YES";
			return;
		}
	}
	cout << "NO";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	solve();
}
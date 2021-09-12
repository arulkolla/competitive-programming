#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int grid[2][n + 7], a[n + 7];
	char temp;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			grid[i][j] = (int)(temp - '0');
		}
	}
	for (int i = 0; i < n; i++) {
		a[i] = grid[0][i] + grid[1][i];
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			res += 2;
		}
		else if (a[i] == 0) {
			if (i < n - 1 && a[i + 1] == 2) {res += 2; i++;}
			else {res += 1;}
		}
		else {
			if (i < n - 1 && a[i + 1] == 0) {res += 2; i++;}
			else {res += 0;}
		}
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	char g[n + 7][n + 7];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (g[i][j] == '#' && g[i - 1][j] == '#' && g[i + 1][j] == '#' && g[i][j - 1] == '#' && g[i][j + 1] == '#') {
				g[i][j] = '.'; g[i - 1][j] = '.'; g[i + 1][j] = '.'; g[i][j - 1] = '.'; g[i][j + 1] = '.';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (g[i][j] == '#') {cout << "NO"; return;}
		}
	}
	cout << "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
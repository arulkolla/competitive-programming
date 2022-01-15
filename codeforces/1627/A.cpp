#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m, r, c;
	cin >> n >> m >> r >> c;
	r--; c--;
	char a[n + 7][m + 7];
	bool hasB = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			hasB |= (a[i][j] == 'B');
		}
	}
	if (!hasB) {cout << -1 << '\n'; return;}
	if (a[r][c] == 'B') {cout << 0 << '\n'; return;}
	bool oneMove = false;
	for (int i = 0; i < n; i++) {
		oneMove |= (a[i][c] == 'B');
	}
	for (int j = 0; j < m; j++) {
		oneMove |= (a[r][j] == 'B');
	}
	if (oneMove) {cout << 1 << '\n';}
	else {cout << 2 << '\n';}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
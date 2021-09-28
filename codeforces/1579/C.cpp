#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	string a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	reverse(a, a + n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != '.') {
				int x1 = j - 1, x2 = j + 1, y = i + 1, d = 0;
				while (0 <= x1 && x1 < m && 0 <= x2 && x2 < m && 0 <= y && y < n && a[y][x1] != '.' && a[y][x2] != '.') {
					d++;
					x1--; x2++; y++;
				}
				if (d >= k) {
					a[i][j] = '!';
					x1 = j - 1, x2 = j + 1, y = i + 1;
					while (0 <= x1 && x1 < m && 0 <= x2 && x2 < m && 0 <= y && y < n && a[y][x1] != '.' && a[y][x2] != '.') {
						a[y][x1] = '!'; a[y][x2] = '!';
						x1--; x2++; y++;
					}
				}
			}
		}
	}
	bool bad = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '*') {bad = true;}
		}
	}
	cout << (bad ? "NO\n" : "YES\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
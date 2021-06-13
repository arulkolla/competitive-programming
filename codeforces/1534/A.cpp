#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	bool r = true, w = true;
	char c[n + 7][m + 7];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
			// cout << c[i][j] << endl;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + j) % 2 == 0) {
				if (c[i][j] == 'W') {r = false;}
			}
			else {
				if (c[i][j] == 'R') {r = false;}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + j) % 2 == 0) {
				if (c[i][j] == 'R') {w = false;}
			}
			else {
				if (c[i][j] == 'W') {w = false;}
			}
		}
	}
	// cout << r << ' ' << w << endl;
	if (!(r || w)) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	if (r) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((i + j) % 2 == 0) {
					cout << 'R';
				}
				else {
					cout << 'W';
				}
			}
			cout << endl;
		}
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((i + j) % 2 == 0) {
					cout << 'W';
				}
				else {
					cout << 'R';
				}
			}
			cout << endl;
		}
		return;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
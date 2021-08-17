#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	char grid[n + 7][m + 7];
	if (n % 2 == 0 && m % 2 == 0) {
		if (k % 2 == 1) {cout << "NO\n"; return;}
		int togo = k / 2;
		for (int i = 0; i < n; i += 2) {
			for (int j = 0; j < m; j += 2) {
				if (togo > 0) {
					if ((i + j) % 4 == 0) {
						grid[i][j] = 'a';
						grid[i][j + 1] = 'a';
						grid[i + 1][j] = 'b';
						grid[i + 1][j + 1] = 'b';	
					}
					else {
						grid[i][j] = 'c';
						grid[i][j + 1] = 'c';
						grid[i + 1][j] = 'd';
						grid[i + 1][j + 1] = 'd';
					}
					togo--;
				}
				else {
					if ((i + j) % 4 == 0) {
						grid[i][j] = 'e';
						grid[i + 1][j] = 'e';
						grid[i][j + 1] = 'f';
						grid[i + 1][j + 1] = 'f';
					}
					else {
						grid[i][j] = 'g';
						grid[i + 1][j] = 'g';
						grid[i][j + 1] = 'h';
						grid[i + 1][j + 1] = 'h';
					}
				}
			}
		}
	}
	else {
		if (n % 2 == 1) {
			if (k < (m / 2)) {cout << "NO\n"; return;}
			k -= m / 2;
			if (k % 2 == 1) {cout << "NO\n"; return;}
			for (int i = 0; i < m; i += 2) {
				if (i % 4 == 0) {
					grid[0][i] = 'i';
					grid[0][i + 1] = 'i';
				}
				else {
					grid[0][i] = 'j';
					grid[0][i + 1] = 'j';
				}
			}
			int togo = k / 2;
			for (int i = 1; i < n; i += 2) {
				for (int j = 0; j < m; j += 2) {
					if (togo > 0) {
						if ((i + j) % 4 == 1) {
							grid[i][j] = 'a';
							grid[i][j + 1] = 'a';
							grid[i + 1][j] = 'b';
							grid[i + 1][j + 1] = 'b';	
						}
						else {
							grid[i][j] = 'c';
							grid[i][j + 1] = 'c';
							grid[i + 1][j] = 'd';
							grid[i + 1][j + 1] = 'd';
						}
						togo--;
					}
					else {
						if ((i + j) % 4 == 1) {
							grid[i][j] = 'e';
							grid[i + 1][j] = 'e';
							grid[i][j + 1] = 'f';
							grid[i + 1][j + 1] = 'f';
						}
						else {
							grid[i][j] = 'g';
							grid[i + 1][j] = 'g';
							grid[i][j + 1] = 'h';
							grid[i + 1][j + 1] = 'h';
						}
					}
				}
			}
		}
		else {
			k = (n * m) / 2 - k;
			if (k < (n / 2)) {cout << "NO\n"; return;}
			k -= n / 2;
			if (k % 2 == 1) {cout << "NO\n"; return;}
			char gridt[m + 7][n + 7];
			for (int i = 0; i < n; i += 2) {
				if (i % 4 == 0) {
					gridt[0][i] = 'i';
					gridt[0][i + 1] = 'i';
				}
				else {
					gridt[0][i] = 'j';
					gridt[0][i + 1] = 'j';
				}
			}
			int togo = k / 2;
			for (int i = 1; i < m; i += 2) {
				for (int j = 0; j < n; j += 2) {
					if (togo > 0) {
						if ((i + j) % 4 == 1) {
							gridt[i][j] = 'a';
							gridt[i][j + 1] = 'a';
							gridt[i + 1][j] = 'b';
							gridt[i + 1][j + 1] = 'b';	
						}
						else {
							gridt[i][j] = 'c';
							gridt[i][j + 1] = 'c';
							gridt[i + 1][j] = 'd';
							gridt[i + 1][j + 1] = 'd';
						}
						togo--;
					}
					else {
						if ((i + j) % 4 == 1) {
							gridt[i][j] = 'e';
							gridt[i + 1][j] = 'e';
							gridt[i][j + 1] = 'f';
							gridt[i + 1][j + 1] = 'f';
						}
						else {
							gridt[i][j] = 'g';
							gridt[i + 1][j] = 'g';
							gridt[i][j + 1] = 'h';
							gridt[i + 1][j + 1] = 'h';
						}
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					grid[i][j] = gridt[j][i];
				}
			}
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
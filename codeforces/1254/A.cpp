#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

const string s = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

void solve() {
	int n, m, c, total = 0;
	cin >> n >> m >> c;
	char field[n + 7][m + 7];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
			if (field[i][j] == 'R') {total++;}
		}
	}
	int curr = 0, cnt = total - total / c * c, goal = total / c, pos = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < m; j++) {
				if (field[i][j] == 'R') {curr++;}
				field[i][j] = s[pos];
				if (cnt > 0 && curr == goal + 1) {
					cnt--;
					curr = 0;
					pos++;
					if (pos > c - 1) {pos--;}
				}
				else if (cnt == 0 && curr == goal) {
					curr = 0;
					pos++;
					if (pos > c - 1) {pos--;}
				}
			}
		}
		else {
			for (int j = m - 1; j >= 0; j--) {
				if (field[i][j] == 'R') {curr++;}
				field[i][j] = s[pos];
				if (cnt > 0 && curr == goal + 1) {
					cnt--;
					curr = 0;
					pos++;
					if (pos > c - 1) {pos--;}
				}
				else if (cnt == 0 && curr == goal) {
					curr = 0;
					pos++;
					if (pos > c - 1) {pos--;}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << field[i][j];
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
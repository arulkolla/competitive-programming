
// Problem: C1. Errich-Tac-Toe (Easy Version)
// Contest: Codeforces - Codeforces Global Round 12
// URL: https://codeforces.com/contest/1450/problem/C1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	char a[n + 7][n + 7];
	int v1 = 0, v2 = 0, v3 = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (j % 3 == (i + 0) % 3 && a[i][j] == 'X') {v1++;}
			if (j % 3 == (i + 1) % 3 && a[i][j] == 'X') {v2++;}
			if (j % 3 == (i + 2) % 3 && a[i][j] == 'X') {v3++;}
			if (a[i][j] == 'X') {cnt++;}
		}
	}
	if (v1 <= cnt / 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j % 3 == (i + 0) % 3 && a[i][j] == 'X') {a[i][j] = 'O';}
				cout << a[i][j];
			}
			cout << endl;
		}
	}
	else if (v2 <= cnt / 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j % 3 == (i + 1) % 3 && a[i][j] == 'X') {a[i][j] = 'O';}
				cout << a[i][j];
			}
			cout << endl;
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j % 3 == (i + 2) % 3 && a[i][j] == 'X') {a[i][j] = 'O';}
				cout << a[i][j];
			}
			cout << endl;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
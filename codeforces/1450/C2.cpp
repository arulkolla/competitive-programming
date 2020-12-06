
// Problem: C2. Errich-Tac-Toe (Hard Version)
// Contest: Codeforces - Codeforces Global Round 12
// URL: https://codeforces.com/contest/1450/problem/C2
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
	int x[3] = {}, o[3] = {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'X') {
				x[(i + j) % 3]++;
			}
			else if (a[i][j] == 'O') {
				o[(i + j) % 3]++;
			}
		}
	}
	int mn = min(min(x[0] + o[1], x[0] + o[2]), min(min(x[1] + o[0], x[1] + o[2]), min(x[2] + o[0], x[2] + o[1])));
	
	// for (int i = 0; i < 3; i++) {cout << x[i] << " ";} cout << endl;
	// for (int i = 0; i < 3; i++) {cout << o[i] << " ";} cout << endl;
	
	int v1, v2;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j) {
				if (mn == x[i] + o[j]) {v1 = i; v2 = j;}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) % 3 == v1 && a[i][j] == 'X') {a[i][j] = 'O';}
			if ((i + j) % 3 == v2 && a[i][j] == 'O') {a[i][j] = 'X';}
			cout << a[i][j];
		}
		cout << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
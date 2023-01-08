#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int lv = 1, rv = n * n, r = 0, c = 0;
	int a[n][n];
	for (int i = 0; i < n * n; i++) {
		if (i % 2 == 0) {a[r][c] = lv; lv++;}
		else {a[r][c] = rv; rv--;}
		if (r % 2 == 0) {
			if (c == n - 1) {r++;}
			else {c++;}
		}
		else {
			if (c == 0) {r++;}
			else {c--;}
		}
	}	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
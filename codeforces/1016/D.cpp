#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	int c[n + 7], r[m + 7], cx = 0, rx = 0;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		cx ^= c[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> r[i];
		rx ^= r[i];
	}
	if (cx != rx) {cout << "NO"; return;}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i < n - 1 && j < m - 1) {cout << 0;}
			else if (j < m - 1) {cout << r[j];}
			else if (i < n - 1) {cout << c[i];}
			else {cout << (rx ^ r[m - 1] ^ c[n - 1]);}
			cout << ' ';
		}
		cout << '\n';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
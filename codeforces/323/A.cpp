
// Problem: A. Black-and-White Cube
// Contest: Codeforces - Testing Round #7
// URL: https://codeforces.com/problemset/problem/323/A
// Memory Limit: 256 MB
// Time Limit: 500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	if (n % 2) {cout << -1;}
	else {
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						if (((j % 4) < 2 && (k % 4) < 2) || ((j % 4) > 1 && (k % 4) > 1)) {cout << 'w';}
						else {cout << 'b';}
					}
					cout << endl;
				}
			}
			else {
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						if (((j % 4) < 2 && (k % 4) < 2) || ((j % 4) > 1 && (k % 4) > 1)) {cout << 'b';}
						else {cout << 'w';}
					}
					cout << endl;
				}
			}
			cout << endl;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
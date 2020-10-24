
// Problem: B. Prime Square
// Contest: Codeforces - Codeforces Round #678 (Div. 2)
// URL: https://codeforces.com/contest/1436/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n / 2; i++) {
		if (i == n / 2 - 1 && n % 2) {
			for (int j = 0; j < n; j++) {
				if (j == 2 * i || j == 2 * i + 1) {
					cout << "1 ";
				}
				else {
					cout << "0 ";
				}	
			}
			cout << endl;
			for (int j = 0; j < n - 1; j++) {
				if (j == 2 * i || j == 2 * i + 1) {
					cout << "1 ";
				}
				else {
					cout << "0 ";
				}	
			}
			cout << "1 ";
			cout << endl;
		}
		else {
			for (int j = 0; j < n; j++) {
				if (j == 2 * i || j == 2 * i + 1) {
					cout << "1 ";
				}
				else {
					cout << "0 ";
				}	
			}
			cout << endl;
			for (int j = 0; j < n; j++) {
				if (j == 2 * i || j == 2 * i + 1) {
					cout << "1 ";
				}
				else {
					cout << "0 ";
				}	
			}
			cout << endl;
		}
	}
	if (n % 2) {
		for (int i = 0; i < n; i++) {
			if (i == n - 1 || i == n - 2) {cout << "1 ";}
			else {cout << "0 ";}
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
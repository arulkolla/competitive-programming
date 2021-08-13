#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long a1, b1, c1;
	cin >> a1 >> b1 >> c1;
	long long a2, b2, c2;
	cin >> a2 >> b2 >> c2;
	if (a1 * b2 == a2 * b1) {
		if (c1 * b2 == c2 * b1 && c1 * a2 == c2 * a1) {
			if (a1 == 0 && a2 == 0 && b1 == 0 && b2 == 0) {
				if (c1 == 0 && c2 == 0) {cout << -1;}
				else {cout << 0;}
			}
			else {cout << -1;}
		}
		else {cout << 0;}
	}
	else {cout << 1;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;
const long double EPS = 1000000000000000000.0L;

void solve() {
	int n;
	cin >> n;
	cout << 3 * n + 2 << '\n';
	cout << fixed << setprecision(17);
	vector<long double> v = {-3090169943749470720.0L, 9510565162951536640.0L, 13090169943749472256, 9510565162951530496.0L, 0.0L, 0.0L, 5000000000000002048.0L, 15388417685876262912.0L, 10000000000000000000.0L, 0.0L};
	for (int i = 0; i < 5; i++) {
		cout << v[2 * i] / EPS << ' ' << v[2 * i + 1] / EPS << '\n';
	}
	vector<long double> u = {39270509831248396288.0L, 9510565162951528448.0L, 31180339887498936320.0L, 15388417685876254720.0L, 36180339887498924032.0L, 1776.36L};
	vector<long double> d = {26180339887498936320.0L, 444.09L, 18090169943749466112.0L, -5877852522924726272.0L, 23090169943749464064.0L, 9510565162951528448.0L};
	long double gap = 26180339887498924032.0L;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i % 2 == 0) {
				cout << (d[2 * j] / EPS) + (gap / EPS) * (i / 2 - 1) << ' ' << (d[2 * j + 1] / EPS) << '\n';
			}
			else {
				cout << (u[2 * j] / EPS) + (gap / EPS) * (i / 2 - 1) << ' ' << (u[2 * j + 1] / EPS) << '\n';
			}
		}
	}
	cout << "1 4 2 5 3\n";
	if (n >= 2) {
		cout << "2 8 6 7 5\n";
	}
	for (int i = 3; i <= n; i++) {
		if (i % 2 == 1) {
			cout << 10 + 6 * (i / 2 - 1) << ' ' << 9 + 6 * (i / 2 - 1) << ' ' << 11 + 6 * (i / 2 - 1) << ' ' << 6 + 6 * (i / 2 - 1) << ' ' << 8 + 6 * (i / 2 - 1) << '\n';
		}
		else {
			cout << 3 + 6 * (i / 2 - 1) << ' ' << 8 + 6 * (i / 2 - 1) << ' ' << 6 + 6 * (i / 2 - 1) << ' ' << 7 + 6 * (i / 2 - 1) << ' ' << 5 + 6 * (i / 2 - 1) << '\n';
		}
	}
	cout << "1 2 3 4 5 ";
	if (n >= 2) {
		cout << "6 2 7 8 ";
	}
	for (int i = 3; i <= n; i++) {
		cout << 3 * i << ' ' << 3 * i - 3 << ' ' << 3 * i + 1 << ' ' << 3 * i + 2 << ' ';
	}
	for (int i = n - 1; i >= 1; i--) {
		cout << 2 + 3 * i << ' ';
	}
	cout << "1";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
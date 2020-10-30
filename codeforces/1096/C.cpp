
// Problem: C. Polygon for the Angle
// Contest: Codeforces - Educational Codeforces Round 57 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1096/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	n *= 2;
	for (int i = 1; i <= n; i++) {
		if (n % i) {continue;}
		int sector = n / i;
		if (360 % sector == 0 && 360 / sector > 2 && (360 - n) * 360 / sector != 360) {cout << 360 / sector << endl; return;}
	}
	cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
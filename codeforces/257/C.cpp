
// Problem: C. View Angle
// Contest: Codeforces - Codeforces Round #159 (Div. 2)
// URL: https://codeforces.com/problemset/problem/257/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

#define PI 3.1415926535897932384

void solve() {
	int n;
	cin >> n;
	long double x, y;
	vector<long double> v;
	for (int i = 0; i < n; i++) {
		long double now;
		cin >> x >> y;
		now = atan2(y, x) * 180 / PI;
		v.push_back(now);
	}
	long double res = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < n - 1; i++) {
		res = max(res, v[i + 1] - v[i]);
	}
	res = max(res, 360 - v[n - 1] + v[0]);
	cout << fixed << setprecision(17) << 360 - res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
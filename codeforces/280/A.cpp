
// Problem: A. Rectangle Puzzle
// Contest: Codeforces - Codeforces Round #172 (Div. 1)
// URL: https://codeforces.com/problemset/problem/280/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long double w, h, a;
	cin >> w >> h >> a;
	if (w < h) {swap(w, h);}
	if (a > 90) {a = 180 - a;}
	long double theta = a * 2 * 3.1415926535897932384 / 360;
	long double x = ((w + h) / (1 + cos(theta) + sin(theta)) + (w - h) / (1 + cos(theta) - sin(theta))) / 2;
	long double y = ((w + h) / (1 + cos(theta) + sin(theta)) - (w - h) / (1 + cos(theta) - sin(theta))) / 2;
	if (2 * atan(h / w) <= theta) {cout << fixed << setprecision(17) << (h * h / sin(theta)); return;}
	cout << fixed << setprecision(17) << w * h - (x * x + y * y) * cos(theta) * sin(theta);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
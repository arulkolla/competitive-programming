
// Problem: D. Polyline
// Contest: Codeforces - Codeforces Round #340 (Div. 2)
// URL: https://codeforces.com/contest/617/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if ((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3)) {cout << 1;}
    else if (x1 == x2 && (y3 - y1) * (y3 - y2) >= 0) {cout << 2;}
    else if (y1 == y2 && (x3 - x1) * (x3 - x2) >= 0) {cout << 2;}
    else if (x1 == x3 && (y2 - y1) * (y2 - y3) >= 0) {cout << 2;}
    else if (y1 == y3 && (x2 - x1) * (x2 - x3) >= 0) {cout << 2;}
    else if (x2 == x3 && (y1 - y2) * (y1 - y3) >= 0) {cout << 2;}
    else if (y2 == y3 && (x1 - x3) * (x1 - x2) >= 0) {cout << 2;}
    else {cout << 3;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
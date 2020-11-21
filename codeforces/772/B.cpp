
// Problem: B. Volatile Kite
// Contest: Codeforces - VK Cup 2017 - Round 2
// URL: https://codeforces.com/contest/772/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

struct pt {
    long double x, y;
    pt(){}
    pt(long double xx, long double yy): x(xx), y(yy) {}
    void read() {long double xx, yy; cin >> xx >> yy; x = xx, y = yy; }
};
 
inline pt operator +(pt p1, pt p2) { return pt(p1.x + p2.x, p1.y + p2.y); }
inline pt operator -(pt p1, pt p2) { return pt(p1.x - p2.x, p1.y - p2.y); }
inline pt operator *(pt p, long double c) { return pt(p.x * c, p.y * c); }
inline pt operator *(long double c, pt p) { return pt(p.x * c, p.y * c); }
 
inline long double magn(pt p) { return sqrt(p.x * p.x + p.y * p.y); }
inline long double dist(pt p1, pt p2) { long double dx = p1.x - p2.x; long double dy = p1.y - p2.y; return sqrt(dx * dx + dy * dy); }
inline long double scal(pt p1, pt p2) { return p1.x * p2.x + p1.y * p2.y; }
inline long double vect(pt p1, pt p2) { return p1.x * p2.y - p1.y * p2.x; }

void solve() {
	int n;
	cin >> n;
	pt a[n + 7];
	for (int i = 0; i < n; i++) {
		a[i].read();
	}
	a[n] = a[0]; a[n + 1] = a[1];
	long double res = 1e37;
	for (int i = 1; i <= n; i++) {
		pt now = a[i + 1] - a[i - 1];
		now = now * (1.0 / magn(now));
		now = pt(-now.y, now.x);
		res = min(res, abs(scal(now, a[i] - a[i - 1])));
	}
	cout << fixed << setprecision(17) << res / 2.0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
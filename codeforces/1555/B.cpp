#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long w, h;
	cin >> w >> h;
	long long x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	long long w2, h2;
	cin >> w2 >> h2;
	long long w1 = x2 - x1, h1 = y2 - y1;
	if (h1 + h2 > h && w1 + w2 > w) {cout << -1 << endl; return;}
	long long l = x1, r = w - x2, u = h - y2, d = y1;
	if (l >= w2 || r >= w2) {cout << 0 << endl; return;}
	if (u >= h2 || d >= h2) {cout << 0 << endl; return;}
	bool wbad = ((w1 + w2) > w), rbad = ((h1 + h2) > h);
	long long ld = w2 - l, rd = w2 - r, ud = h2 - u, dd = h2 - d;
	// cout << ld << ' ' << rd << ' ' << ud << ' ' << dd << endl;
	if (wbad) {
		cout << min(ud, dd) << endl;
	}
	else if (rbad) {
		cout << min(ld, rd) << endl;
	}
	else {
		cout << min(min(ld, rd), min(ud, dd)) << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
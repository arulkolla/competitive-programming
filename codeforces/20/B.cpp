#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long a, b, c;
	cin >> a >> b >> c;
	cout << fixed << setprecision(17);
	if (a == 0 && b == 0) {
		if (c == 0) {cout << -1 << endl; return;}
		else {cout << 0 << endl; return;}
	}
	if (a == 0) {cout << 1 << endl << (long double)(-c) / b << endl; return;}
	if (b * b - 4ll * a * c < 0) {cout << 0 << endl; return;}
	if (b * b - 4ll * a * c == 0) {cout << 1 << endl << (long double)(-b)/(2ll * a); return;}
	cout << 2 << endl;
	long double v1 = (long double)(-b - sqrt(b * b - 4ll * a * c))/(2ll * a), v2 = (long double)(-b + sqrt(b * b - 4ll * a * c))/(2ll * a);
	cout << min(v1, v2) << endl << max(v1, v2) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
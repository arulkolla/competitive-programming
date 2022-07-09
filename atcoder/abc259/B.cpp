#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

const double pi = acos(-1);
const complex<double> i(0, 1);

void solve() {
	double a, b, d;
	cin >> a >> b >> d;
	complex<double> z(a, b);
	z *= exp(d / 180 * pi * i);
	cout << fixed << setprecision(20) << z.real() << ' ' << z.imag() << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	solve();
}
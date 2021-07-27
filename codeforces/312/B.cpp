#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << fixed << setprecision(17) << (a / b) / (1 - (1 - a / b) * (1 - c / d));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
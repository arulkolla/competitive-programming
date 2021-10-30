#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

bool good(long long x, long long y, long long t) {
	return (t % x == y % t);
}

void solve() {
	long long x, y;
	cin >> x >> y;
	if (x > y) {cout << x + y << '\n';}
	else if (x == y) {cout << x << '\n';}
	else {cout << y - ((y / 2) % (x / 2)) << '\n';}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
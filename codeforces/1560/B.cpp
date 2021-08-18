#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long a, b, c;
	cin >> a >> b >> c;
	if (2 * abs(a - b) < a || 2 * abs(a - b) < b || 2 * abs(a - b) < c) {
		cout << -1 << '\n';
	}
	else {
		if (c > abs(a - b)) {cout << c - abs(a - b) << '\n';}
		else {cout << c + abs(a - b) << '\n';}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
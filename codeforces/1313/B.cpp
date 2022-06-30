#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n, x, y;
	cin >> n >> x >> y;
	if (x + y <= n) {
		cout << 1 << ' ' << x + y - 1 << '\n';
	}
	else {
		cout << min(x + y - n + 1, n) << ' ' << n << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
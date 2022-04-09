#include <bits/stdc++.h>

using namespace std;

const int MAX = 32777;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int res = MOD;
	if (n == 0) {cout << 0 << ' '; return;}
	for (int i = 0; i <= 16; i++) {
		res = min(res, i + (15 - __builtin_ctz(n + i)));
	}
	cout << res << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
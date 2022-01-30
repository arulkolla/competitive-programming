#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int a, b;
	cin >> a >> b;
	int res = MOD;
	for (int i = 0; i <= b; i++) {
		if ((i | b) == b) {
			res = min(res, abs(a - i) + (i != b));
		}
	}
	cout << res << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
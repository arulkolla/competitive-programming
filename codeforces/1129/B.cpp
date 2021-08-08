#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long k;
	cin >> k;
	k += 2000;
	cout << 2000 << endl;
	cout << -1 << ' ';
	for (int i = 0; i < 1999; i++) {
		cout << min(1000000ll, k) << ' ';
		k -= min(1000000ll, k);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
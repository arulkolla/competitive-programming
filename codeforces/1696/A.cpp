#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, z;
	cin >> n >> z;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mx = max(mx, x | z);
	}
	cout << mx << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
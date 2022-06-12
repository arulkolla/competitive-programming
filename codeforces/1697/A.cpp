#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long m;
	cin >> n >> m;
	m = -m;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		m += x;
	}
	cout << max(m, 0LL) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
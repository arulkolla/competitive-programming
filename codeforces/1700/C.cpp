#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long res = 0;
	for (int i = 1; i < n; i++) {
		a[i] -= res;
		if (a[i] > a[i - 1]) {res += a[i] - a[i - 1]; a[i] = a[i - 1];}
	}
	cout << res + a[0] + 2 * max(0LL, -a[n - 1]) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
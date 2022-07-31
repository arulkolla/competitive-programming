#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long k;
	cin >> n >> k;
	long long l = MOD, r = -MOD, cnt = 0;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		l = min(l, x);
		r = max(r, x);
		if (r - l > 2 * k) {
			l = x;
			r = x;
			cnt++;
		}
	}
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
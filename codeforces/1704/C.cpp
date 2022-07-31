#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int m, n;
	cin >> m >> n;
	int a[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	a[n] = a[0];
	vector<int> dist;
	for (int i = 1; i <= n; i++) {
		int curr = a[i] - a[i - 1] - 1;
		if (curr < 0) {curr += m;}
		dist.push_back(curr);
		// cout << curr << ' ';
	}
	// cout << '\n';
	sort(dist.begin(), dist.end(), greater<int>());
	int res = 0, curr = 0;
	for (int i : dist) {
		int x = i;
		x -= curr;
		// cout << i << ' ' << curr << ' ' << x << '\n';
		if (x == 1) {
			res++;
			curr++;
		}
		else if (x > 1) {
			res += x - 1;
			curr += 4;
		}
		// cout << res << '\n';
	}
	cout << m - res << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
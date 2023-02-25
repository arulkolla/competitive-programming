#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long nC2(long long x) {
	return ((x * (x - 1)) / 2);
}

void solve() {
	int n, m;
	cin >> n >> m;
	long long alive[n + m + 1], tot[n + m + 1];
	long long res = (long long)n * (long long)m * (long long)(m + 1);
	for (int i = 1; i <= n + m; i++) {
		alive[i] = -1;
		tot[i] = 0;
	}
	int a[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		alive[a[i]] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int p, v;
		cin >> p >> v;
		if (a[p] == v) {continue;}
		tot[a[p]] += i - alive[a[p]];
		// res += nC2((long long)());
		alive[a[p]] = -1;
		alive[v] = i;
		a[p] = v;
		// for (int x = 1; x <= n + m; x++) {cout << alive[x] << ' ';} cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		tot[a[i]] += m - alive[a[i]] + 1;
		// res += nC2((long long)(m - alive[a[i]] + 1));
	}
	for (int i = 1; i <= n + m; i++) {
		res -= nC2(tot[i]);
	}
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
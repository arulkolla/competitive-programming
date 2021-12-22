#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long nC2(long long n) {
	return (n * (n - 1)) / 2;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int x[n + 7], y[m + 7];
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> y[i];
	}
	sort(x, x + n);
	sort(y, y + m);
	map<int, int> xc, yc;
	map<pair<int, int>, long long> xover, yover;
	long long xv[n + 7], yv[m + 7];
	for (int i = 0; i < n; i++) {
		xc[x[i]] = i + 1;
		xv[i + 1] = 0;
	}
	for (int i = 0; i < m; i++) {
		yc[y[i]] = i + 1;
		yv[i + 1] = 0;
	}
	for (int i = 0; i < k; i++) {
		int xi, yi;
		cin >> xi >> yi;
		if ((xc[xi] == 0) ^ (yc[yi] == 0)) {
			if (xc[xi] == 0) {
				int v = lower_bound(x, x + n, xi) - x;
				assert(1 <= v && v <= n);
				xover[make_pair(v, yc[yi])]++;
				xv[v]++;
			}
			else {
				int v = lower_bound(y, y + m, yi) - y;
				assert(1 <= v && v <= m);
				yover[make_pair(xc[xi], v)]++;
				yv[v]++;
			}
		}
	}
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		res += nC2(xv[i]);
	}
	for (int i = 1; i <= m; i++) {
		res += nC2(yv[i]);
	}
	for (auto p : xover) {
		res -= nC2(p.second);
	}
	for (auto p : yover) {
		res -= nC2(p.second);
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
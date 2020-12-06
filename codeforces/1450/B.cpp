
// Problem: B. Balls of Steel
// Contest: Codeforces - Codeforces Global Round 12
// URL: https://codeforces.com/contest/1450/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long dist(pair<long long, long long> a, pair<long long, long long> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve() {
	int n;
	long long k;
	cin >> n >> k;
	pair<long long, long long> a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0; i < n; i++) {
		long long mx = -1;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				mx = max(mx, dist(a[i], a[j]));
			}
		}
		if (mx <= k) {cout << 1 << endl; return;}
	}
	cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}

// Problem: E. Squares and not squares
// Contest: Codeforces - Codeforces Round #451 (Div. 2)
// URL: https://codeforces.com/contest/898/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long a;
	pair<long long, long long> b[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a;
		long long next = ceil(sqrt(a)) * ceil(sqrt(a)), prev = floor(sqrt(a)) * floor(sqrt(a));
		b[i].first = min(next - a, a - prev);
		b[i].second = a;
	}
	sort(b, b + n);
	long long cost = 0;
	for (int i = 0; i < n / 2; i++) {
		cost += b[i].first;
	}
	for (int i = n / 2; i < n; i++) {
		cost += (!(b[i].first) ? (!(b[i].second) ? 2ll : 1ll) : 0ll);
	}
	cout << cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
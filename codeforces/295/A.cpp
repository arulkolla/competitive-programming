
// Problem: A. Greg and Array
// Contest: Codeforces - Codeforces Round #179 (Div. 1)
// URL: https://codeforces.com/contest/295/problem/A
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	long long a[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	pair<pair<long long, long long>, long long> op[m + 7];
	for (int i = 1; i <= m; i++) {
		cin >> op[i].first.first >> op[i].first.second >> op[i].second;
	}
	long long diff1[m + 7];
	for (int i = 0; i < m + 7; i++) {
		diff1[i] = 0;
	}
	for (int i = 0; i < k; i++) {
		int l, r;
		cin >> l >> r;
		diff1[l]++;
		diff1[r + 1]--;
	}
	for (int i = 1; i <= m; i++) {
		diff1[i] += diff1[i - 1];
		op[i].second *= diff1[i];
	}
	long long diff[n + 7];
	for (int i = 0; i < n + 7; i++) {
		diff[i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		diff[op[i].first.first] += op[i].second;
		diff[op[i].first.second + 1] -= op[i].second;
	}
	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
		a[i] += diff[i];
		cout << a[i] << " ";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
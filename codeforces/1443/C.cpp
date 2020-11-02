
// Problem: C. The Delivery Dilemma
// Contest: Codeforces - Codeforces Round #681 (Div. 2, based on VK Cup 2019-2020 - Final)
// URL: https://codeforces.com/contest/1443/problem/C
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
	pair<long long, long long> a[MAX];
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
	}
	long long total = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].second;
		total += a[i].second;
	}
	sort(a, a + n);
	long long mx = total;
	for (int i = 0; i < n; i++) {
		total -= a[i].second;
		mx = min(mx, max(total, a[i].first));
	}
	cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
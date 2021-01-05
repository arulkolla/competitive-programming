
// Problem: A. Strange Partition
// Contest: Codeforces - Codeforces Round #694 (Div. 2)
// URL: https://codeforces.com/contest/1471/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long x;
	cin >> n >> x;
	long long a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	} 
	long long small = 0, big = 0;
	for (int i = 0; i < n; i++) {
		small += (a[i] + x - 1) / x;
		big += a[i];
	}
	big = (big + x - 1) / x;
	cout << min(big, small) << ' ' << max(big, small) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
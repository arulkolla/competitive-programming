
// Problem: C. Eugene and an array
// Contest: Codeforces - Codeforces Round #632 (Div. 2)
// URL: https://codeforces.com/contest/1333/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	map<long long, long long> mp;
	long long sum = 0, res = 0, cnt = -1;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum == 0 && cnt <= 0) {cnt = 0;}
		if (mp.find(sum) != mp.end()) {cnt = max(cnt, mp[sum] + 1);}
		res += cnt + 1;
		mp[sum] = i;
	}
	cout << (1LL * n * (n + 1)) / 2 - res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
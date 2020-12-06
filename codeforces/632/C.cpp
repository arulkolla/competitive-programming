
// Problem: C. The Smallest String Concatenation
// Contest: Codeforces - Educational Codeforces Round 9
// URL: https://codeforces.com/contest/632/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

inline bool cmp(const string& a, const string& b) {
    return a + b < b + a;
}

void solve() {
	int n;
	cin >> n;
	string a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
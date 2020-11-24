
// Problem: C. Palindrome Transformation
// Contest: Codeforces - Codeforces Round #277 (Div. 2)
// URL: https://codeforces.com/contest/486/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;
	long long res = 0;
	n--; p--;
	if (p > n / 2) {p = n - p;}
	int l = -1, r = 0;
	vector<int> need;
	for (int i = 0; i <= n / 2; i++) {
		long long diff = abs(s[i] - s[n - i]);
		if (diff != 0) {
			res += min(diff, 26 - diff);
			if (l < 0) {l = i;}
			else {r = i;}
		}
	}
	res += min(abs(p - l), abs(p - r));
	res += max(r - l, 0);
	if (l < 0) {cout << 0 << endl;}
	else {cout << res << endl;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
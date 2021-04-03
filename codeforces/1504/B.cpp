// Problem: B. Flip the Bits
// Contest: Codeforces - Codeforces Round #712 (Div. 2)
// URL: https://codeforces.com/contest/1504/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int bal = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {bal++;}
		if (t[i] == '1') {bal--;}
	}
	if (bal != 0) {cout << "NO" << endl; return;}
	int sum = 0;
	if (s[0] == '0') {sum--;}
	else {sum++;}
	for (int i = 1; i < n; i++) {
		if ((s[i] != t[i]) != (s[i - 1] != t[i - 1])) {
			if (sum != 0) {
				// cout << i << ' ' << sum << endl;
				cout << "NO" << endl; return;
			}
		}
		if (s[i] == '0') {sum--;}
		else {sum++;}
	}
	cout << "YES" << endl; return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
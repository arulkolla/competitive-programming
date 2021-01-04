
// Problem: B. Fair Division
// Contest: Codeforces - Codeforces Round #693 (Div. 3)
// URL: https://codeforces.com/contest/1472/problem/B
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
	int a[n + 7];
	long long sum = 0;
	bool has1 = false, has2 = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		if (a[i] == 1) {has1 = true;}
		if (a[i] == 2) {has2 = true;}
	}
	if (sum % 2 || (!has1 && (sum / 2) % 2)) {cout << "NO" << endl; return;}
	else {cout << "YES" << endl; return;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
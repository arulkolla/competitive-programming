
// Problem: C. Magic Formulas
// Contest: Codeforces - Codeforces Round #242 (Div. 2)
// URL: https://codeforces.com/contest/424/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long pref[MAX];
	pref[0] = 0;
	for (int i = 1; i <= n + 7; i++) {
		pref[i] = i ^ pref[i - 1];
	}
	long long res = 0, p;
	for (int i = 1; i <= n; i++) {
		cin >> p;
		res ^= p;
		if (n / i % 2) {res ^= pref[i - 1];}
		res ^= pref[n % i];
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
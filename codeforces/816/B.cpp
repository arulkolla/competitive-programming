
// Problem: B. Karen and Coffee
// Contest: Codeforces - Codeforces Round #419 (Div. 2)
// URL: https://codeforces.com/contest/816/problem/B
// Memory Limit: 512 MB
// Time Limit: 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k, q;
	cin >> n >> k >> q;
	int diff[MAX] = {};
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		diff[l]++;
		diff[r + 1]--;
	}
	for (int i = 1; i <= MAX; i++) {
		diff[i] += diff[i - 1];
	}
	
	// for (int i = 89; i <= 101; i++) {cout << i << " ";} cout << endl;
	// for (int i = 89; i <= 101; i++) {cout << diff[i] << "  ";} cout << endl;
	
	int pref[MAX] = {};
	for (int i = 1; i <= MAX; i++) {
		pref[i] = (diff[i] >= k) + pref[i - 1];
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		cout << pref[r] - pref[l - 1] << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
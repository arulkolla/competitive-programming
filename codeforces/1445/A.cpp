
// Problem: A. Array Rearrangment
// Contest: Codeforces - Codeforces Round #680 (Div. 2, based on Moscow Team Olympiad)
// URL: https://codeforces.com/contest/1445/problem/A
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[MAX], b[MAX];
	for (int i = 0; i < n; i++) {cin >> a[i];}
	for (int i = 0; i < n; i++) {cin >> b[i];}
	sort(a, a + n);
	sort(b, b + n);
	reverse(b, b + n);
	for (int i = 0; i < n; i++) {
		if (a[i] + b[i] > k) {cout << "No" << endl; return;}
	}
	cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
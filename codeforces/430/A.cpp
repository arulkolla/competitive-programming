
// Problem: A. Points and Segments (easy)
// Contest: Codeforces - Codeforces Round #245 (Div. 2)
// URL: https://codeforces.com/contest/430/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[MAX], b[MAX], cnt[MAX] = {};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		cnt[a[i]] = i % 2;
	}
	for (int i = 0; i < n; i++) {
		cout << cnt[b[i]] << " ";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
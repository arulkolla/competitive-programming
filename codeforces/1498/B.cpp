// Problem: B. Box Fitting
// Contest: Codeforces - CodeCraft-21 and Codeforces Round #711 (Div. 2)
// URL: https://codeforces.com/contest/1498/problem/B
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
	int w;
	cin >> n >> w;
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, greater<int>());
	int cnt[20] = {};
	for (int i = 0; i < n; i++) {
		int rn = -1;
		while (a[i]) {
			rn++;
			a[i] >>= 1;
		}
		cnt[rn]++;
	}
	int ht[MAX] = {};
	for (int i = 19; i >= 0; i--) {
		int curr = (1 << i), pt = 0;
		for (int j = 0; j < cnt[i]; j++) {
			while (w - ht[pt] < curr) {
				pt++;
			}
			ht[pt] += curr;
		}
	}
	int res = 0;
	for (int i = 0; i < MAX; i++) {
		if (ht[i] == 0) {res = i; break;}
		// else {cout << ht[i] << ' ' << i << endl;}
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
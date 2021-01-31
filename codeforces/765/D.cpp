
// Problem: D. Artsem and Saunders
// Contest: Codeforces - Codeforces Round #397 by Kaspersky Lab and Barcelona Bootcamp (Div. 1 + Div. 2 combined)
// URL: https://codeforces.com/contest/765/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	bool ok[MAX] = {};
	vector<int> a[MAX];
	vector<int> oks;
	int k;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		a[k].push_back(i);
		if (k == i) {ok[i] = true; oks.push_back(k);}
	}
	bool really = false;
	for (int i = 1; i <= n; i++) {
		if (!ok[i] && !a[i].empty()) {
			really = true;
		}
	}
	if (really) {cout << -1 << endl; return;}
	cout << oks.size() << endl;
	int cnt = 0;
	int res[MAX];
	for (int i = 1; i <= n; i++) {
		if (!a[i].empty()) {
			cnt++;
			for (int j : a[i]) {
				res[j] = cnt;
			}
		}
	}
	for (int i = 1; i<= n; i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	for (int i : oks) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
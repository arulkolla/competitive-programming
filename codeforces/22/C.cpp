
// Problem: C. System Administrator
// Contest: Codeforces - Codeforces Beta Round #22 (Div. 2 Only)
// URL: https://codeforces.com/problemset/problem/22/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void put(int a, int b) {
	cout << a << " " << b << endl;
}

void solve() {
	long long n, m, vs;
	cin >> n >> m >> vs;
	if (m < n - 1 || m > ((n - 1) * (n - 2)) / 2 + 1) {cout << -1; return;}
	vector<int> v;
	v.push_back(vs);
	for (int i = 1; i <= n; i++) {
		if (i != vs) {v.push_back(i);}
	}
	put(v[0], v[1]);
	put(v[0], v[2]);
	for (int i = 3; i < n; i++) {
		put(v[0], v[i]);
	}
	int done = n - 1;
	for (int i = 2; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (done >= m) {break;}
			else {put(v[i], v[j]); done++;}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
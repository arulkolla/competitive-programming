
// Problem: C. Valera and Tubes
// Contest: Codeforces - Codeforces Round #252 (Div. 2)
// URL: https://codeforces.com/problemset/problem/441/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int> > v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i % 2 == 1) {v.push_back(make_pair(i, j));}
			else {v.push_back(make_pair(i, m + 1 - j));}
		}
	}
	for (int i = 0; i < k - 1; i++) {
		cout << 2 << " ";
		cout << v[2 * i].first << " " << v[2 * i].second << " ";
		cout << v[2 * i + 1].first << " " << v[2 * i + 1].second << " ";
		cout << endl;
	}
	cout << n * m - 2 * k + 2 << " ";
	for (int i = 2 * k - 2; i < n * m; i++) {
		cout << v[i].first << " " << v[i].second << " ";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
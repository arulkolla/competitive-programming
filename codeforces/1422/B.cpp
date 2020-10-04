
// Problem: B. Nice Matrix
// Contest: Codeforces - Codeforces Round #675 (Div. 2)
// URL: https://codeforces.com/contest/1422/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 107;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	int a[MAX][MAX];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	map<pair<int, int>, vector<int> > mp;
	set<pair<int, int> > list;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			pair<int, int> dist = make_pair(abs(2*i - (n - 1)), abs(2*j - (m - 1)));
			mp[dist].push_back(a[i][j]);
			list.insert(dist);
		}
	}
	long long res = 0;
	for (pair<int, int> i : list) {
		sort(mp[i].begin(), mp[i].end());
		int mn, mn2;
		if (mp[i].size() == 1) {mn = mp[i][0]; mn2 = mp[i][0];}
		else if (mp[i].size() == 2) {mn = mp[i][1]; mn2 = mp[i][0];}
		else if (mp[i].size() == 4) {mn = mp[i][2]; mn2 = mp[i][1];}
		long long one = 0, two = 0;
		for (int j : mp[i]) {
			one += abs(j - mn);
		}
		for (int j : mp[i]) {
			two += abs(j - mn);
		}
		res += min(one, two);
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
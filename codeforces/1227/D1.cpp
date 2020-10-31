
// Problem: D1. Optimal Subsequences (Easy Version)
// Contest: Codeforces - Technocup 2020 - Elimination Round 3
// URL: https://codeforces.com/contest/1227/problem/D1
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[MAX];
	vector<pair<int, int> > v; 
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v.push_back(make_pair(MOD - a[i], i + 1));
	}
	sort(v.begin(), v.end());
	int q;
	cin >> q;
	for (int qq = 0; qq < q; qq++) {
		int num, ind;
		cin >> num >> ind;
		ind--;
		vector<pair<int, int> > w;
		for (int i = 0; i < num; i++) {
			w.push_back(make_pair(v[i].second, MOD - v[i].first));
		}
		sort(w.begin(), w.end());
		cout << w[ind].second << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
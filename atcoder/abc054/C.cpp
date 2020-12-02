
// Problem: C - One-stroke Path
// Contest: AtCoder - AtCoder Beginner Contest 054
// URL: https://atcoder.jp/contests/abc054/tasks/abc054_c
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int v, e;
	cin >> v >> e;
	map<pair<int, int>, bool> mp;
	for (int i = 0; i < e; i++) {
		int p, q;
		cin >> p >> q;
		mp[make_pair(p, q)] = true;
		mp[make_pair(q, p)] = true;
	}
	vector<int> vert;
	for (int i = 2; i <= v; i++) {
		vert.push_back(i);
	}
	int res = 0;
	do {
		bool bad = false;
		for (int i = 1; i < vert.size(); i++) {
			if (!mp[make_pair(vert[i], vert[i - 1])]) {bad = true;}
		}
		if (!mp[make_pair(vert[0], 1)]) {bad = true;}
		if (!bad) {res++;}
	} while (next_permutation(vert.begin(), vert.end()));
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	solve();
}

// Problem: D. Love Rescue
// Contest: Codeforces - Codeforces Round #464 (Div. 2)
// URL: https://codeforces.com/problemset/problem/939/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 27;
const int MOD = 1000000007;

int a[MAX], sz[MAX], cnt[MAX];
bool head[MAX];

int find(int p) {
	while (p != a[p]) {
		a[p] = a[a[p]];
		p = a[p];
	}
	return p;
}

bool connected(int p, int q) {
	return find(p) == find(q);
}

void dsu(int p, int q) {
	int i = find(p);
	int j = find(q);
	if (i != j) {
		if (sz[i] < sz[j]) {cnt[j] += cnt[i]; a[i] = j; head[i] = false;}
		else if (sz[i] > sz[j]) {cnt[i] += cnt[j]; a[j] = i; head[j] = false;}
		else {
			cnt[i] += cnt[j];
			a[j] = i;
			head[j] = false;
			sz[i]++;
		}
	}
}

void solve() {
	int n;
	cin >> n;
	string v, t;
	cin >> v >> t;
	for (int i = 0; i < 26; i++) {
		a[i] = i;
		sz[i] = 0;
		cnt[i] = 1;
		head[i] = true;
	}
	for (int i = 0; i < n; i++) {
		if (v[i] != t[i]) {
			dsu(v[i] - 'a', t[i] - 'a');
		}
	}
	bool check[MAX] = {false};
	long res = 0;
	for (int i = 0; i < 26; i++) {
		if (head[i] && cnt[i] > 1) {
			check[i] = true;
			res += cnt[i] - 1;
		}
	}
	map<int, vector<int> > mp;
	for (int i = 0; i < 26; i++) {
		int k = find(i);
		if (check[k] == true) {
			mp[k].push_back(i);
		}
	}
	cout << res << endl;
	for (int i = 0; i < 26; i++) {
		if (check[i] == true) {
			for (int j = 0; j < mp[i].size() - 1; j++) {
				cout << (char)('a' + mp[i][j]) << " " << (char)('a' + mp[i][j + 1]) << endl;
			}
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
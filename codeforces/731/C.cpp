#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

struct DSU {
	vector<int> e;
	DSU(int N) {e = vector<int>(N, -1);}
	
	int get(int x) {return e[x] < 0 ? x : e[x] = get(e[x]);}

	bool same_set(int a, int b) {return get(a) == get(b);}

	int size(int x) {return -e[get(x)];}

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

void solve() {
	int n, m, k, a[MAX];
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	DSU dsu(n + 7);
	map<int, int> mp;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		dsu.unite(u, v);
	}
	int curr = 0;
	for (int i = 1; i <= n; i++) {
		if (dsu.get(i) == i) {mp[i] = curr; curr++;}
	}
	vector<vector<int> > cc(curr);
	for (int i = 1; i <= n; i++) {
		cc[mp[dsu.get(i)]].push_back(a[i]);
	}
	int res = 0;
	for (auto v : cc) {
		sort(v.begin(), v.end());
		int val = v[0], cnt = 1, mx = 1, sz = (int)v.size();
		for (int i = 1; i < sz; i++) {
			if (v[i] == val) {cnt++;}
			else {
				mx = max(mx, cnt);
				val = v[i];
				cnt = 1;
			}
		}
		mx = max(mx, cnt);
		res += (sz - mx);
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
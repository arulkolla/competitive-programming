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
	int cnt(int k) {
		set<int> s;
		for (int i = 1; i <= k; i++) {
			s.insert(get(i));
		}
		return (int)s.size();
	}
};

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	DSU d(n + m + 7);
	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		d.unite(u, n + v);
	}
	cout << d.cnt(n + m) - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
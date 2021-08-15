#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

void solve() {
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	DSU d1(n), d2(n);
	int v1, v2;
	for (int i = 0; i < m1; i++) {
		cin >> v1 >> v2;
		v1--; v2--;
		d1.unite(v1, v2);
	}	
	for (int i = 0; i < m2; i++) {
		cin >> v1 >> v2;
		v1--; v2--;
		d2.unite(v1, v2);
	}	
	vector<pair<int, int> > v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!d1.same_set(i, j) && !d2.same_set(i, j)) {
				v.emplace_back(i, j);
				d1.unite(i, j);
				d2.unite(i, j);
			}
		}
	}
	cout << v.size() << endl;
	for (pair<int, int> p : v) {
		cout << p.first + 1 << ' ' << p.second + 1 << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
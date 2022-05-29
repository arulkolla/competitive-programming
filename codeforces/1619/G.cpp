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

int cnt = 0;

void solve() {
	cnt++;
	int n, k;
	cin >> n >> k;
	vector<pair<pair<int, int>, int>> reg, rev;
	vector<int> time(n);
	DSU dsu(n);
	for (int i = 0; i < n; i++) {
		pair<int, int> p;
		cin >> p.first >> p.second >> time[i];
		reg.push_back(make_pair(p, i));
		rev.push_back(make_pair(make_pair(p.second, p.first), i));
	}
	sort(reg.begin(), reg.end());
	sort(rev.begin(), rev.end());
	for (int i = 1; i < n; i++) {
		if (reg[i].first.first == reg[i - 1].first.first && reg[i].first.second - reg[i - 1].first.second <= k) {
			dsu.unite(reg[i - 1].second, reg[i].second);
		}
		if (rev[i].first.first == rev[i - 1].first.first && rev[i].first.second - rev[i - 1].first.second <= k) {
			dsu.unite(rev[i - 1].second, rev[i].second);
		}
	}
	vector<int> opts(n, MOD);
	for (int i = 0; i < n; i++) {
		int x = dsu.get(i);
		opts[x] = min(opts[x], time[i]);
	}
	vector<int> times;
	for (int i = 0; i < n; i++) {
		if (opts[i] != MOD) {times.push_back(opts[i]);}
	}
	// for (int i : times) {cout << i << ' ';} cout << '\n';
	sort(times.begin(), times.end());
	int l = 0, r = times.size() - 1, curr = 0;
	while (l <= r) {
		r--;
		while (l < times.size() && times[l] == curr) {l++;}
		curr++;
	}
	cout << curr - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
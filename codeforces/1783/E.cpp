#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

template<class T> struct Seg {
	const T ID = 0; T comb(T a, T b) {return a + b;}
	int n; vector<T> seg;
	void init(int _n) {n = _n; seg.assign(2 * n, ID);}
	void pull(int p) {seg[p] = comb(seg[2 * p], seg[2 * p + 1]);}
	void upd(int p, T val) {
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p);
	}
	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra, seg[l++]);
			if (r&1) rb = comb(seg[--r], rb);
		}
		return comb(ra, rb);
	}
};

void solve() {
	int n;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	set<int> s; // bads
	int mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, a[i] - b[i]);
	}
	if (mx > 0) {
		for (int i = 1; i <= mx; i++) {
			s.insert(i);
		}
	}
	Seg<int> st;
	st.init(n + 7);
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			st.upd(b[i], st.query(b[i], b[i]) + 1);
			st.upd(a[i], st.query(a[i], a[i]) - 1);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (st.query(1, i) > 0) {
			for (int x = 1; x * x <= i; x++) {
				if (i % x == 0) {
					s.insert(x);
					s.insert(i / x);
				}
			}
		}
	}
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (s.find(i) == s.end()) {v.push_back(i);}
	}
	cout << v.size() << '\n';
	for (int i : v) {cout << i << ' ';} cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

template <class T> struct segtree { // cmb(ID,b) = b
	const T ID{0}; T cmb(T a, T b) { return a+b; } 
	int n; vector<T> seg;
	void init(int _n) {
		for (n = 1; n < _n; ) n *= 2; 
		seg.assign(2*n,ID); 
	}
	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { 
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); 
	}
	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
};

void solve() {
	int n;
	cin >> n;
	segtree<long long> st; st.init(n + 7);
	long long a[n + 7], tot = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		tot += a[i];
	}
	vector<int> v;
	int left = 0;
	for (int i = n; i >= 1; i--) {
		// cout << tot << '\n';
		// for (int j = 1; j <= i; j++) {
			// cout << a[j] + st.query(1, j) << ' ';
		// }
		// cout << '\n';
		if (tot <= 0) {
			while (v.size() < n) {v.push_back(0);}
			break;
		}
		if (tot == (long long)i * i) {
			while (v.size() < n) {v.push_back(1);}
			break;
		}
		int bits = tot / i;
		if (a[i] + st.query(1, i) == 1) {
			v.push_back(0);
		}
		else {
			v.push_back(1);
		}
		st.upd(i - bits + 1, st.query(i - bits + 1, i - bits + 1) - 1);
		st.upd(i + 1, st.query(i + 1, i + 1) + 1);
		tot -= (long long)bits;
		tot -= (a[i] + st.query(1, i));
		// for (int j = 1; j <= i; j++) {
			// cout << a[j] + st.query(1, j) << ' ';
		// }
		// cout << "<--- axed";
		// cout << '\n';
		// cout << tot << '\n' << '\n';
	}
	reverse(v.begin(), v.end());
	for (int i : v) {
		cout << i << ' ';
	}
	cout << '\n';
	// cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
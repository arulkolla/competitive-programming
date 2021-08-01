#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long gcd(long long a, long long b) {
	if (b == 0ll) {return a;}
	return gcd(b, a % b);
}

template<class T> struct Seg {
	const T ID{}; T comb(T a, T b) { return gcd(a, b); }
	int n; vector<T> seg;
	void init(int _n) { // upd, query also work if n = _n
		for (n = 1; n < _n; ) n *= 2; 
		seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// any associative op on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
	int first_at_least(int lo, long long val, int ind, int l, int r) { // if seg stores max across range
		if (r < lo || val > seg[ind]) return -1;
		if (l == r) return l;
		int m = (l+r)/2;
		int res = first_at_least(lo,val,2*ind,l,m); if (res != -1) return res;
		return first_at_least(lo,val,2*ind+1,m+1,r);
	}
};

int firstTrue(int lo, int hi, function<bool(int)> f) {
	for (hi++; lo < hi; ) {
		int mid = lo+(hi-lo)/2;
		if (f(mid)) hi = mid;
		else lo = mid+1;
	}
	return lo;
}

void solve() {
	int n;
	cin >> n;
	long long a[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << 1 << '\n';
		return;
	}
	Seg<long long> tree;
	tree.init(n + 1);
	for (int i = 1; i <= n - 1; i++) {
		tree.upd(i, abs(a[i + 1] - a[i]));
	}
	int mx = 0;
	for (int i = 1; i <= n - 1; i++) {
		mx = max(mx, i - firstTrue(1, i, [&tree, i](int x) { return tree.query(x, i) > 1ll; }) + 1);
	}
	cout << mx + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
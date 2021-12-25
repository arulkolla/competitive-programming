#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

template<class T> struct Seg {
	const T ID = 0; T comb(T a, T b) {return a + b;}
	int n; vector<T> seg;
	void init(int _n) {n = _n; seg.assign(2*n,ID);}
	void pull(int p) {seg[p] = comb(seg[2*p],seg[2*p+1]);}
	void upd(int p, T val) {seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p);}
	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

void solve() {
	int n;
	cin >> n;
	pair<long long, long long> a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i].second;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
	}
	sort(a, a + n);
	map<long long, long long> mp;
	long long curr = 1;
	// for (int i = 0; i < n; i++) {
		// cout << a[i].first << ' ' << a[i].second << '\n';
	// } cout << '\n';
	mp[a[0].first] = curr;
	for (int i = 1; i < n; i++) {
		if (a[i].first != a[i - 1].first) {curr++; mp[a[i].first] = curr;}
	}
	for (int i = 0; i < n; i++) {
		swap(a[i].first, a[i].second);
	}
	sort(a, a + n);
	reverse(a, a + n);
	// for (int i = 0; i < n; i++) {
		// cout << a[i].first << ' ' << mp[a[i].second] << '\n';
	// } cout << '\n';
	Seg<long long> stsum, stcnt;
	stsum.init(n + 7);
	stcnt.init(n + 7);
	stsum.upd(mp[a[0].second], a[0].first);
	stcnt.upd(mp[a[0].second], 1);
	long long res = 0;
	for (int i = 1; i < n; i++) {
		// cout << stsum.query(mp[a[i].second], n + 5) << ' ' << stcnt.query(mp[a[i].second], n + 5) << '\n';
		res += (stsum.query(mp[a[i].second], n + 5) - a[i].first * stcnt.query(mp[a[i].second], n + 5));
		stsum.upd(mp[a[i].second], stsum.query(mp[a[i].second], mp[a[i].second]) + a[i].first);
		stcnt.upd(mp[a[i].second], stcnt.query(mp[a[i].second], mp[a[i].second]) + 1);
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
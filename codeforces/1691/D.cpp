#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

template<class T> struct segmax {
	const T ID = -MOD; T comb(T a, T b) {return max(a, b);}
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

template<class T> struct segadd {
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
	vector<long long> a;
	long long temp[n];
	// vector<int> pos;
	segadd<long long> sega;
	segmax<long long> segm;
	sega.init(n);
	segm.init(n);
	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}
	bool fail = false;
	long long curr = temp[0];
	for (int i = 1; i < n; i++) {
		if ((temp[i - 1] > 0) ^ (temp[i] > 0)) {
			a.push_back(curr);
			curr = temp[i];
		}
		else {
			curr += temp[i];
		}
		if (temp[i] > 0 && temp[i - 1] > 0) {fail = true;}
	}
	if (fail) {cout << "NO\n"; return;}
	a.push_back(curr);
	if (a[0] <= 0) {a.erase(a.begin());}
	if (!a.empty() && a[a.size() - 1] <= 0) {a.pop_back();}
	if (a.empty()) {cout << "YES\n"; return;}
	// for (long long i : a) {cout << i << '\n';}
	for (int i = 0; i < a.size(); i++) {
		sega.upd(i, a[i]);
		segm.upd(i, a[i]);
	}
	stack<int> st;
	st.push(0);
	for (int i = 2; i < a.size(); i += 2) {
		int x = -1;
		while (true) {
			if (st.empty() || a[st.top()] > a[i]) {st.push(i); break;}
			else {
				if (st.size() == 1) {x = st.top();}
				st.pop();
			}
		}
		if (x == -1) {
			st.pop();
			x = st.top();
			st.push(i);
		}
		// cout << x << ' ' << i << '\n';
		if (x != i - 2 && a[i - 1] + a[i - 2] > 0LL) {cout << "NO\n"; return;}
		if (segm.query(x, i) < sega.query(x, i)) {cout << "NO\n"; return;}
	}
	cout << "YES\n";
	// for (int i = 1; i < pos.size(); i++) {
		// // pos[i - 1] .. pos[i]
		// cout << segm.query(pos[i - 1], pos[i]) << ' ' << sega.query(pos[i - 1], pos[i]) << '\n';
		// if (segm.query(pos[i - 1], pos[i]) < sega.query(pos[i - 1], pos[i])) {cout << "NO\n"; return;}
	// }
	// cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
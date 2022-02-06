#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int a[MAX];

int query(int i, int j, int k) {
	cout << "? " << i << ' ' << j << ' ' << k << endl;
	int x;
	// int x = max(max(a[i], a[j]), a[k]) - min(min(a[i], a[j]), a[k]);
	// cout << "Response: " << x << '\n';
	cin >> x;
	assert(x != -1);
	return x;
}

void solve() {
	int n;
	cin >> n;
	// for (int i = 1; i <= n; i++) {
		// cin >> a[i];
	// }
	int mx = -1, mxi = -2;
	bool same = true;
	for (int i = 3; i <= n; i++) {
		int resp = query(1, 2, i);
		if (mx != -1 && resp != mx) {same = false;}
		if (resp > mx) {mx = resp; mxi = i;}
	}
	if (same) {
		int r1 = query(1, 3, 4), r2 = query(2, 3, 4);
		if (r1 < mx || r2 < mx) {mxi = 1;}
	}
	int other = 1;
	if (mxi == 1) {other = 2;}
	mx = -1;
	same = true;
	int mni = other;
	for (int i = 1; i <= n; i++) {
		if (mxi != i && other != i) {
			int resp = query(mxi, other, i);
			if (mx != -1 && resp != mx) {same = false;}
			if (resp > mx) {mx = resp; mni = i;}
		}
	}
	if (same) {
		mni = other;
	}
	// if (mni == other) {
		// int smn;
		// for (int i = 1; i <= n; i++) {
			// if (mxi != i && other != i && mex != i) {smn = i; break;}
		// }
		// int q = query(mex, mxi, smn);
		// if (q == mx) {mni = mex;}
		// else if (q > mx) {mni = smn;}
	// }
	cout << "! " << mxi << ' ' << mni << endl;
	// if (a[mxi] == 0 || a[mni] == 0) {cout << "YES\n";}
	// else {cout << "NO\n";}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
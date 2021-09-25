#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int query(int l, int r) {
	assert(l <= r);
	if (l == r) {return -MOD;}
	cout << "? " << l << ' ' << r << endl;
	int res;
	cin >> res;
	return res;
}

void solve() {
	int n;
	cin >> n;
	int pos = query(1, n);
	int l = 1, r = n;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (pos < l) {
			int res = query(pos, mid);
			if (res == pos) {r = mid;}
			else {l = mid + 1;}
		}
		else if (pos > r) {
			int res = query(mid + 1, pos);
			if (res == pos) {l = mid + 1;}
			else {r = mid;}
		}
		else {
			if (pos <= mid) {
				int res = query(l, mid);
				if (res == pos) {r = mid;}
				else {l = mid + 1;}
			}
			else {
				int res = query(mid + 1, r);
				if (res == pos) {l = mid + 1;}
				else {r = mid;}
			}
		}
	}
	cout << "! " << l << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
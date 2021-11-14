#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long query(int l, int r) {
	cout << "? " << l << ' ' << r << endl;
	long long resp;
	cin >> resp;
	assert(resp != -1);
	return resp;
}

void answer(long long i, long long j, long long k) {
	cout << "! " << i << ' ' << j << ' ' << k << endl;
}

void solve() {
	int n;
	cin >> n;
	long long total = query(1, n);
	int l = 1, r = n;
	while (r > l) {
		int m = l + (r - l) / 2;
		if (query(1, m) == total) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	long long y = total - query(1, l - 1) + 1, xv = total - (y * (y - 1)) / 2;
	long long x = (long long)((sqrt(8 * xv + 1) + 1) / 2);
	// for (long long i = 1; i <= 2000007ll; i++) {
		// if ((i * (i - 1)) / 2 == xv) {x = i; break;}
	// }
	answer(l - y - x + 1, l - y + 1, l);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
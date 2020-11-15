
// Problem: B. Well-known Numbers
// Contest: Codeforces - Codeforces Round #139 (Div. 2)
// URL: https://codeforces.com/problemset/problem/225/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n, k;
	cin >> n >> k;
	long long a[MAX] = {};
	if (n == 1) {cout << "2\n1 0"; return;}
	if (k >= 40) {
		cout << __builtin_popcount(n) << endl;
		long long rn = 1;
		while (n > 0) {
			if (n & 1) {
				// curr bit is set
				cout << rn << " ";
			}
			rn *= 2;
			n >>= 1;
		}
		return;
	}
	a[k] = 1;
	long long curr = a[k], ptr = k + 1;
	while (curr <= n + 7) {
		a[ptr] = curr;
		curr += a[ptr];
		curr -= a[ptr - k];
		ptr++;
	}
	a[ptr] = curr;
	long long now = n;
	vector<long long> v;
	v.push_back(0);
	for (int i = ptr; i >= k; i--) {
		if (a[i] <= now) {
			now -= a[i];
			v.push_back(a[i]);
		}
	}
	cout << v.size() << endl;
	for (long long i : v) {
		cout << i << " ";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
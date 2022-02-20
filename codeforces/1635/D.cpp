#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int add(int x, int y) {
	return (x + y) % MOD;
}

int sub(int x, int y) {
	return add(x, MOD - y);
}

void solve() {
	int n, p;
	cin >> n >> p;
	int a[n + 7];
	set<int> good;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		int x = a[i];
		while (true) {
			if (x == 0) {
				good.insert(a[i]);
				break;
			}
			else if ((x & 1) == 1) {
				x >>= 1;
			}
			else if ((x & 3) == 0) {
				x >>= 2;
			}
			else {
				good.insert(a[i]);
				break;
			}
			if (good.find(x) != good.end()) {
				break;
			}
		}
	}
	int fib[p + 7];
	fib[1] = 1; fib[2] = 2;
	for (int i = 3; i < p + 7; i++) {
		fib[i] = add(fib[i - 1], fib[i - 2]);
	}
	int pfib[p + 7];
	pfib[0] = 0;
	for (int i = 1; i < p + 7; i++) {
		pfib[i] = add(pfib[i - 1], fib[i]);
	}
	int res = 0;
	for (auto i : good) {
		int lg = 0;
		while (i > 0) {
			i >>= 1;
			lg++;
		}
		if (p - lg < 0) {continue;}
		res = add(res, add(pfib[p - lg], 1));
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}

/*

101
10100
100111
11001000

101
1011
10100
10111
100111
101001
101100
101111
1001111
1010000
1010011
1011001
1011100
1011111
*/
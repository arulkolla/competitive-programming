#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n, l, r;
	cin >> n >> l >> r;
	for (long long i = l; i <= r; i++) {
		if (i == n * (n - 1) + 1) {cout << 1;}
		else {
			long long val = (n * (n - 1))/ 2 - ((i + 1) / 2) + 1;
			long long tri = (long long)ceil((sqrt((long double)8.0 * val + 1) - 1) / 2);
			long long excess = 1 + (tri * (tri + 1) / 2 - val);
			// cout << i << ": " << val << " (" << tri << ',' << excess << ")\n";
			if (i % 2 == 1) {cout << n - tri;}
			else {cout << n - tri + excess;}
		}
		cout << ' ';
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000007;
const int MOD = 1000000007;

void solve() {
	long long n;
	cin >> n;
	long long pow2 = 2;
	while ((n & 1) == 0) {n >>= 1; pow2 <<= 1;}
	if (n == 1) {n = -1;}
	cout << min(pow2, n) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
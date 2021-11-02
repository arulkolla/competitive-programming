#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n, x;
	cin >> n >> x;
	long long beg = (x / 4) * 4 + 1;
	for (long long i = beg; i <= x; i++) {
		if (n % 2 == 0) {n -= i;}
		else {n += i;}	
	}
	cout << n << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
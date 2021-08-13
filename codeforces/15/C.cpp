#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long pxor(long long n) {
	if (n % 4 == 0) {return n;}
	else if (n % 4 == 1) {return 1ll;}
	else if (n % 4 == 2) {return n + 1;}
	else {return 0ll;}
}

void solve() {
	int n;
	cin >> n;
	long long x = 0;
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		x ^= pxor(a + b - 1);
		x ^= pxor(a - 1);
	}
	cout << (x ? 't' : 'b') << "olik";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
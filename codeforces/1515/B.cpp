#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

bool ok(long long n) {
	long long rt = sqrt(n);
	return (rt * rt == n);
}

void solve() {
	long long n;
	cin >> n;
	if (n % 2 == 0) {
		if (ok(n / 2)) {cout << "YES" << endl; return;}
	}
	if (n % 4 == 0) {
		if (ok(n / 4)) {cout << "YES" << endl; return;}
	}
	cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long u, v;
	cin >> n >> u >> v;
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	bool two = false, one = false;
	for (int i = 1; i < n; i++) {
		if (abs(a[i] - a[i - 1]) >= 1) {one = true;}
		if (abs(a[i] - a[i - 1]) >= 2) {two = true;}
	}
	if (two) {cout << 0 << endl;}
	else if (one) {cout << min(u, v) << endl;}
	else {cout << v + min(u, v) << endl;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
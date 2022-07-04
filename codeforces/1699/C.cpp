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

int mul(int x, int y) {
	return (x * 1ll * y) % MOD;
}

void solve() {
	int n;
	cin >> n;
	int a[n], pos[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}	
	if (n == 1) {cout << 1 << '\n'; return;}
	int l = pos[0], r = pos[0], sub = 0, res = 1;
	for (int i = 1; i < n; i++) {
		if (pos[i] < l) {l = pos[i];}
		else if (r < pos[i]) {r = pos[i];}
		else {res = mul(res, r - l + 1 - i);}
	}
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}

// Problem: E. Apollo versus Pan
// Contest: Codeforces - Good Bye 2020
// URL: https://codeforces.com/contest/1466/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long add(long long x, long long y) {
	x %= MOD;
	y %= MOD;
	return (x + y) % MOD;
}

long long sub(long long x, long long y) {
	while (y < 0) {y += MOD;}
	x %= MOD;
	y %= MOD;
	return add(x, MOD - y);
}

long long mul(long long x, long long y) {
	x %= MOD;
	y %= MOD;
	return (x * 1ll * y) % MOD;
}

void solve() {
	long long n;
	cin >> n;
	long long a[n + 7];
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum = add(sum, a[i]);
	}
	long long res = 0;
	long long sums[n + 7];
	for (int i = 0; i < n + 5; i++) {sums[i] = 0;}
	for (int i = 0; i < 62; i++) {
		long long zero = 0, one = 0;
		long long val = 1ll << i;
		for (int j = 0; j < n; j++) {
			if (a[j] & (val)) {one = add(1, one);}
			else {zero = add(1, zero);}
		}
		one = mul(one, val);
		zero = mul(zero, val);
		for (int j = 0; j < n; j++) {
			if (a[j] & (val)) {sums[j] = add(sums[j], zero);}
			else {sums[j] = add(sums[j], one);}
		}
	}

	for (int i = 0; i < n; i++) {
		long long v1 = add(mul(a[i], n), sum);
		long long curr = mul(v1, v1);
		long long v2 = mul(sums[i], sums[i]);
		curr = sub(curr, v2);
		res = add(res, curr);
	}
	cout << mul(250000002ll, res) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
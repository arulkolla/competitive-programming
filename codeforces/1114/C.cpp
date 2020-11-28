
// Problem: C. Trailing Loves (or L'oeufs?)
// Contest: Codeforces - Codeforces Round #538 (Div. 2)
// URL: https://codeforces.com/contest/1114/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long legendre(long long n, long long nb) {
	long long res = 0;
	while (n != 0) {
		res += (n / nb);
		n /= nb;
	}
	return res;
}

void solve() {
	long long n, b;
	cin >> n >> b;
	long long res = 1e18;
	for (long long i = 2; i <= b; i++) {
		if (i * i > b) {i = b;}
		long long cnt = 0;
		while (b % i == 0) {
			b /= i;
			cnt++;
		}
		if (cnt != 0) {
			res = min(res, legendre(n, i) / cnt);
		}
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
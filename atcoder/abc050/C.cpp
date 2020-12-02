
// Problem: C - Lining Up
// Contest: AtCoder - AtCoder Beginner Contest 050
// URL: https://atcoder.jp/contests/abc050/tasks/arc066_a
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
	int n;
	cin >> n;
	int a[n + 7], cnt[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) {cnt[a[i]]++;}
	for (int i = 0; i < n; i++) {
		if (n % 2 == 0) {
			if (i % 2) {
				if (cnt[i] != 2) {cout << 0; return;}
			}
			else {
				if (cnt[i] != 0) {cout << 0; return;}
			}
		}
		else {
			if (i % 2) {
				if (cnt[i] != 0) {cout << 0; return;}
			}
			else if (i != 0) {
				if (cnt[i] != 2) {cout << 0; return;}
			}
			else {
				if (cnt[i] != 1) {cout << 0; return;}
			}
		}
	}
	long long val = 1LL * (n / 2);
	cout << binpow(2LL, val, MOD);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}

// Problem: C. Permutation Cycle
// Contest: Codeforces - ICM Technex 2018 and Codeforces Round #463 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/problemset/problem/932/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long gcd(long long a, long long b) {
	if (b == 0) {return a;}
	return gcd(b, a % b);
}

void solve() {
	long long n, a, b;
	cin >> n >> a >> b;
	if (n % gcd(a, b)) {cout << -1; return;}
	long long av = -1, bv = -1;
	for (long long i = 0; i <= n; i++) {
		if ((n - a * i) % b == 0) {av = i; bv = (n - a * i) / b; break;}
	}
	if (bv < 0 || av < 0) {cout << -1; return;}
	if (av == 0 || bv == 0) {
		if (bv == 0) {
			if (a == 1) {for (long long i = 1; i <= n; i++) {cout << i << " ";} return;}
			for (long long i = 1; i <= av; i++) {
				for (long long j = 0; j < a; j++) {
					cout << ((j + 1) % a) + a * i - (a - 1) << " ";
				}
			}
		}
		else if (av == 0) {
			if (b == 1) {for (long long i = 1; i <= n; i++) {cout << i << " ";} return;}
			for (long long i = 1; i <= bv; i++) {
				for (long long j = 0; j < b; j++) {
					cout << ((j + 1) % b) + b * i - (b - 1) << " ";
				}
			}
		}
		return;
	}
	// for (long long i = 1; i <= av; i++) {
		// for (long long j = 0; j < a; j++) {
			// cout << ((j + 1) % a) + a * i - (a - 1) << " ";
		// }
	// }
	// for (long long i = av + 1; i <= bv + av; i++) {
		// for (long long j = 0; j < b; j++) {
			// cout << ((j + 1) % b) + b * i - (b - 1) << " ";
		// }
	// }
	for (long long i = 1; i <= av; i++) {
		for (long long j = 0; j < a; j++) {
			cout << ((j + 1) % a) + i * a + 1 - a << " ";
		}
	}
	for (long long i = 1; i <= bv; i++) {
		for (long long j = 0; j < b; j++) {
			cout << ((j + 1) % b) + i * b + 1 - b + a * av << " ";
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
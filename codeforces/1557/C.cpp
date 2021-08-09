#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
        	res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long binpowm(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
        	res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

long long inv(long long n) {
	return binpow(n, MOD - 2);
}

void solve() {
	long long n, k;
	cin >> n >> k;
	long long x = binpow(2ll, n - 1);
	if (n % 2 == 1) {
		cout << binpow((x + 1ll) % MOD, k) % MOD << endl;
	}
	else {
		cout << (((x * binpow(x - 1, k)) % MOD + binpow(binpow(2ll, n), k)) % MOD) * inv(x + 1) % MOD << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
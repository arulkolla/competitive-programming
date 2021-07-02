#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const long long MOD = 1000000007;

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

long long inv(long long a) {
	return binpow(a, MOD - 2) % MOD;
}

long long mul(long long a, long long b) {
	return ((a) % MOD * 1ll * b) % MOD;
}

void solve() {
	int n;
	long long m;
	cin >> n >> m;
	int a[n + 7], b[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	long long res = 0, curr = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0 && b[i] == 0) {
			res = (res + mul(curr, mul(m - 1, inv(2 * m)))) % MOD;
			curr = mul(curr, inv(m));
		}
		else if (a[i] == 0) {
			res = (res + mul(curr, mul(m - b[i], inv(m)))) % MOD;
			curr = mul(curr, inv(m));
		}
		else if (b[i] == 0) {
			res = (res + mul(curr, mul(a[i] - 1, inv(m)))) % MOD;
			curr = mul(curr, inv(m));
		}
		else if (a[i] == b[i]) {
			continue;
		}
		else {
			if (a[i] > b[i]) {res = (res + curr) % MOD;}
			break;
		}
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
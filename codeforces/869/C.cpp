#include <bits/stdc++.h>

using namespace std;

const int MAX = 5007;
const int MOD = 998244353;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

int a, b, c;
int fact[MAX], infact[MAX];

int add(int x, int y) {
	return (x + y) % MOD;
}

int sub(int x, int y) {
	return add(x, MOD - y);
}

int mul(int x, int y) {
	return (x * 1ll * y) % MOD;
}

int binpow(int x, int y) {
    x %= MOD;
    int res = 1;
    while (y > 0) {
        if (y & 1) {
        	res = mul(res, x);
        }
        x = mul(x, x);
        y >>= 1;
    }
    return res;
}

int inv(int x) {
	return binpow(x, MOD - 2);
}

int C(int n, int k) {
	if (n < 0 || k < 0 || n < k) {return 0;}
	return mul(fact[n], (mul(infact[k], infact[n - k])));
}

void solve() {
	cin >> a >> b >> c;
	int v1 = 0, v2 = 0, v3 = 0;
	for (int i = 0; i < a + b + c; i++) {
		v1 = add(v1, mul(fact[i], mul(C(a, i), C(b, i))));
		v2 = add(v2, mul(fact[i], mul(C(b, i), C(c, i))));
		v3 = add(v3, mul(fact[i], mul(C(c, i), C(a, i))));
	}
	cout << mul(v1, mul(v2, v3));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = 1;
    infact[0] = 1;
    for (int i = 1; i < MAX; i++) {
    	fact[i] = mul(fact[i - 1], i);
    	infact[i] = mul(infact[i - 1], inv(i));
    }
    solve();
}
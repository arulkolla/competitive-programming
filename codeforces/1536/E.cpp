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

void solve() {
	int n, m;
	cin >> n >> m;
	long long cnt = 0;
	char c;
	bool ok = false;
	for (int i = 0; i < n * m; i++) {
		cin >> c;
		if (c == '#') {cnt++;}
		else {ok = true;}
	}
	long long res = binpow(2ll, cnt);
	if (!ok) {res--;}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
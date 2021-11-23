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
	int n;
	cin >> n;
	int a;
	long long mp[37] = {};
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		int cnt = 0;
		while (a % 2 == 0) {
			a /= 2;
			cnt++;
		}
		mp[cnt]++;
	}
	
	for (int i = 35; i >= 0; i--) {
		mp[i] += mp[i + 1];
	}
	set<long long> s;
	for (int i = 1; i < 36; i++) {
		s.insert(mp[i]);
	}
	long long res = binpow(2ll, (long long)n);
	for (long long i : s) {
		res -= binpow(2ll, i - 1);
	}
	while (res < MOD) {res += MOD;}
	res %= MOD;
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
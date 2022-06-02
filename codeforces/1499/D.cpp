#include <bits/stdc++.h>

using namespace std;

const int MAX = 20'000'007;
const int MOD = 1000000007;

bool sieve[MAX] = {};
int t[MAX] = {};

void solve() {
	long long c, d, x, r = 0;
	cin >> c >> d >> x;
	for (long long k = 1; k * k <= x; k++) {
		if (x % k == 0) {
			if ((d * k + x) % (c * k) == 0) {
				r += (1LL << t[(d * k + x) / (c * k)]);
			}
			if (k * k != x) {
				if ((d + k) % c == 0) {
					r += (1LL << t[(d + k) / c]);
				}
			}
		}
	}
	cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 2; i < MAX; i++) {
    	if (!sieve[i]) {
	    	for (int j = i; j < MAX; j += i) {
	    		sieve[j] = true;
	    		t[j]++;
	    	}
    	}
    }
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
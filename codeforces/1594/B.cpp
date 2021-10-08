#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n, k;
	cin >> n >> k;
	long long pown = 1, res = 0;
	while (k) {
		if (k & 1) {res += pown; res %= MOD;}
		k >>= 1;
		pown *= n; pown %= MOD;
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000007;
const int MOD = 1000000007;

long long a[MAX], b[MAX];

void solve() {
	int n;
	cin >> n;
	a[1] = 1;
	b[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) {
			a[i] = a[i - 1];
			b[i] = a[i - 1] + b[i - 1] + 1;
		}
		else {
			a[i] = a[i - 1] + b[i - 1] + 1;
			b[i] = b[i - 1];
		}
		a[i] %= MOD;
		b[i] %= MOD;
	}
	cout << (a[n] + b[n]) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
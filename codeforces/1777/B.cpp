#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int prec[MAX];

int mul(int x, int y) {
	return (x * 1ll * y) % MOD;
}

void solve() {
	int n;
	cin >> n;
	cout << prec[n] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int curr = 1;
	for (int i = 1; i < MAX; i++) {
		curr = mul(curr, i);
		prec[i] = mul(mul(curr, i), i - 1);
	}
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
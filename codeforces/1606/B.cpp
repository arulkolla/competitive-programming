#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n, k;
	cin >> n >> k;
	long long curr = 1, res = 0;
	while (curr < n && curr <= k) {
		curr <<= 1;
		res++;
	}
	cout << res + (n - curr + k - 1) / k << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
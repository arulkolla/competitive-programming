#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long a[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long res = -1000000000007;
	for (int i = 1; i <= n; i++) {
		res = max(res, a[i] - i);
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
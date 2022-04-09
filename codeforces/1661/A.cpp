#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long a[n + 7], b[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	long long res = 0;
	for (int i = 1; i < n; i++) {
		long long v1 = abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]);
		long long v2 = abs(b[i] - a[i - 1]) + abs(a[i] - b[i - 1]);
		res += min(v1, v2);
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
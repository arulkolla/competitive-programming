#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[2 * n + 7];
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}
	sort(a, a + (2 * n));
	cout << (a[n - 1] < a[n] ? "YES" : "NO");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
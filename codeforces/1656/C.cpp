#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n;
	int a[n + 7];
	bool zero = false, one = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		zero |= (a[i] == 0);
		one |= (a[i] == 1);
	}
	if (!one) {cout << "YES\n";}
	else if (zero && one) {cout << "NO\n";}
	else {
		sort(a, a + n);
		for (int i = 1; i < n; i++) {
			if (a[i] == a[i - 1] + 1) {cout << "NO\n"; return;}
		}
		cout << "YES\n";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
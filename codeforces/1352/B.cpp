#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	if (n < k) {cout << "NO\n"; return;}
	if (k % 2 == 0) {
		if (n % 2 == 1) {cout << "NO\n"; return;}
		cout << "YES\n";
		for (int i = 0; i < k - 1; i++) {
			cout << 1 << ' ';
		}
		cout << n - k + 1 << '\n';
	}
	else {
		if (n % 2 == 1) {
			cout << "YES\n";
			for (int i = 0; i < k - 1; i++) {
				cout << 1 << ' ';
			}
			cout << n - k + 1 << '\n';
		}
		else {
			if (n < 2 * k) {cout << "NO\n"; return;}
			cout << "YES\n";
			for (int i = 0; i < k - 1; i++) {
				cout << 2 << ' ';
			}
			cout << n - 2 * k + 2 << '\n';
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
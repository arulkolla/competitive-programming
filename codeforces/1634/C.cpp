#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << "YES\n";
		for (int i = 1; i <= n * k; i++) {
			cout << i << '\n';
		}
	}
	else {
		if (n % 2 == 1) {cout << "NO\n";}
		else {
			cout << "YES\n";
			for (int i = 1; i <= n * k; i += 2 * k) {
				for (int j = i; j < i + 2 * k; j += 2) {
					cout << j << ' ';
				}
				cout << '\n';
				for (int j = i + 1; j < i + 2 * k; j += 2) {
					cout << j << ' ';
				}
				cout << '\n';
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
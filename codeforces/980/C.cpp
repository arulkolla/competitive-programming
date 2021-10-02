#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[257];
	for (int i = 0; i < 257; i++) {
		a[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (a[x] == -1) {
			for (int j = max(0, x - k + 1); j <= x; j++) {
				if (a[j] == -1 || a[j] == j) {
					for (int k = j; k <= x; k++) {a[k] = j;}
					break;
				}
			}
		}
		cout << a[x] << ' ';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
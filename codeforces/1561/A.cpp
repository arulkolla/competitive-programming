#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (is_sorted(a, a + n)) {cout << 0 << '\n'; return;}
	int i = 0;
	while (true) {
		i++;
		if (i % 2 == 1) {
			for (int j = 0; j < n - 1; j += 2) {
				if (a[j] > a[j + 1]) {swap(a[j], a[j + 1]);}
			}
		}
		else {
			for (int j = 1; j < n; j += 2) {
				if (a[j] > a[j + 1]) {swap(a[j], a[j + 1]);}
			}
		}
		if (is_sorted(a, a + n)) {cout << i << '\n'; return;}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
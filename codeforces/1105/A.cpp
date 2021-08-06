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
	int mn = MOD, top;
	for (int t = 1; t <= 100; t++) {
		int curr = 0;
		for (int i = 0; i < n; i++) {
			curr += min(abs(t - a[i]), min(abs(t - (a[i] + 1)), abs(t - (a[i] - 1))));
		}
		if (curr < mn) {
			mn = curr;
			top = t;
		}
	}
	cout << top << ' ' << mn << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
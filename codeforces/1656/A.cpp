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
	int mn = MOD, mx = -MOD;
	int mni, mxi;
	for (int i = 0; i < n; i++) {
		if (a[i] < mn) {
			mni = i;
			mn = a[i];
		}
		if (a[i] > mx) {
			mxi = i;
			mx = a[i];
		}
	}
	cout << mni + 1 << ' ' << mxi + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
	    cin >> a[i];
	}
	if (k > 1) {
	    int res = 0;
	    for (int i = 1; i < n - 1; i++) {
	        res += (a[i] > a[i - 1] + a[i + 1]);
	    }
	    cout << res << '\n';
	}
	else {
	    cout << (n - 1) / 2 << '\n';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
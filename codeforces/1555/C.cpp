#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long a[n + 7], b[n + 7];
	a[0] = 0; b[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		b[i] += b[i - 1];
	}
	long long best = 1000000000007ll, curr;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			curr = a[n] - a[i];
		}
		else if (i == n) {
			curr = b[i - 1] - b[0];
		}
		else {
			curr = max(a[n] - a[i], b[i - 1] - b[0]);
		}
		best = min(best, curr);
	}
	cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
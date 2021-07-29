#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long k;
	cin >> k;
	long long a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long best = -1000000000000000ll;
	for (int i = 0; i < n; i++) {
		for (int j = max(i - 407, 0); j < i; j++) {
			best = max(best, (long long)(i + 1) * (j + 1) - k * (a[i] | a[j]));
		}
	}
	cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
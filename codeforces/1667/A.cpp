#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n;
	cin >> n;
	long long a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long res = LLONG_MAX;
	for (int i = 0; i < n; i++) {
		long long last = 0, tot = 0;
		for (int j = i + 1; j < n; j++) {
			long long curr = last / a[j];
			last = (curr + 1) * a[j];
			tot += curr + 1;
		}
		last = 0;
		for (int j = i - 1; j >= 0; j--) {
			long long curr = last / a[j];
			last = (curr + 1) * a[j];
			tot += curr + 1;
		}
		res = min(res, tot);
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
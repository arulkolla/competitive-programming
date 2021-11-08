#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[n + 7], ind[n + 7], curr = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) {ind[curr] = i; curr++;}
	}
	if (curr > k) {cout << -1; return;}
	if (curr == 0) {cout << 0; return;}
	k -= curr;
	int res = curr * 2;
	curr--;
	int pref[n + 7];
	for (int i = 0; i < curr; i++) {
		pref[i] = ind[i + 1] - ind[i] - 1;
	}
	sort(pref, pref + curr);
	for (int i = 0; i < curr; i++) {
		if (k >= pref[i]) {
			res -= 2;
			k -= pref[i];
		}
	}
	if (n - ind[curr] - 1 <= k) {res--;}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
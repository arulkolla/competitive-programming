#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	multiset<int> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n); // greater<int>();
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 2 * a[k]) {k++;}
	}
	cout << n - min(k, n / 2);
	// for (int _ = 0; _ < 1; _++) {
		// res++;
		// auto it = s.end();
		// it--;
		// int curr = *it;
		// cout << curr << ' ';
		// s.erase(curr);
		// while (curr > 1) {
			// auto itx = s.lower_bound(curr / 2);
			// cout << *itx << ' ';
			// curr = *itx;
			// // s.erase(itx);
			// // if (itx == s.begin()) {break;}
		// }
		// cout << '\n';
	// }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
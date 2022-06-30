#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (a[i] > 0) {a[i]--; cnt++;}
	}
	sort(a, a + 3, greater<int>());
	for (int i = 0; i < 3; i++) {
		if (a[i] > 0 && a[(i + 1) % 3] > 0) {a[i]--; a[(i + 1) % 3]--; cnt++;}
	}
	if (a[0] > 0 && a[1] > 0 && a[2] > 0) {cnt++;}
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
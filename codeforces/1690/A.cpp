#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[3] = {2, 3, 1};
	for (int i = 7; i <= n; i++) {
		if (i % 3 == 1) {a[1]++;}
		else if (i % 3 == 2) {a[0]++;}
		else {a[2]++;}
	}
	cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
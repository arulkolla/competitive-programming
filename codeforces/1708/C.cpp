#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, q;
	cin >> n >> q;
	int a[n];
	string s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += '0';
	}
	int curr = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] <= curr) {s[i] = '1';}
		else if (curr < q) {curr++; s[i] = '1';}
	}
	cout << s << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long odd = 0, even = 0, x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (i % 2 == 0) {odd += x;}
		else {even += x;}
	}
	if (n % 2 == 0) {
		cout << (odd <= even ? "YES\n" : "NO\n");
	}
	else {
		cout << "YES\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
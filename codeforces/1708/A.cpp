#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int x;
	cin >> x;
	bool ok = true;
	for (int i = 0; i < n - 1; i++) {
		int y;
		cin >> y;
		if (y % x != 0) {ok = false;}
	}	
	cout << (ok ? "YES\n" : "NO\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
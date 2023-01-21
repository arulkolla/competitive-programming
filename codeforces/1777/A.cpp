#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n];
	int c = n - 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0 && (a[i] % 2 != a[i - 1] % 2)) {c--;}
	}	
	cout << c << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
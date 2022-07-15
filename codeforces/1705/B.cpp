#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	long long res = 0;
	bool ok = false;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] != 0) {ok = true; res += a[i];}
		if (a[i] == 0) {
			if (ok) {res++;}
		}
	}
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
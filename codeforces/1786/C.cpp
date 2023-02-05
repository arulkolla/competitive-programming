#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	sort(a + 1, a + n + 1);
	int curr = 0;
	long long tot = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > curr) {curr++; tot += (a[i] - curr);}
	}
	cout << tot << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
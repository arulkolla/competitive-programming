#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long a[n + 1], p[n + 1];
	p[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
	}
	for (int i = 1; i < n; i++) {
		if (p[i] < 0) {cout << "No\n"; return;}
		else if (p[i] == 0 && p[i + 1] != 0) {cout << "No\n"; return;}
	}
	cout << (p[n] == 0 ? "Yes" : "No") << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
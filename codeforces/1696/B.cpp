#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n];
	vector<int> pos;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] != 0) {pos.push_back(i);}
	}
	if (pos.empty()) {cout << 0 << '\n'; return;}
	bool ok = true;
	for (int i = 1; i < pos.size(); i++) {
		if (pos[i] != pos[i - 1] + 1) {ok = false;}
	}
	cout << (ok ? 1 : 2) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
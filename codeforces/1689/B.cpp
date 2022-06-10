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
	if (n == 1) {cout << -1 << '\n'; return;}
	bool used[n + 1];
	for (int i = 1; i <= n; i++) {
		used[i] = false;
	}
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		bool ok = false;
		for (int j = 1; j <= n; j++) {
			if (!used[j] && j != a[i]) {used[j] = true; ok = true; v.push_back(j); break;}
		}
		if (!ok) {v.push_back(i); swap(v[n - 1], v[n - 2]);}
	}
	for (int i : v) {cout << i << ' ';} cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
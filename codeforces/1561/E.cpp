#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	bool ok = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] % 2 != i % 2) {ok = false;}
	}
	if (!ok) {cout << -1 << '\n'; return;}
	vector<int> v;
	for (int val = n; val >= 3; val -= 2) {
		for (int i = 1; i <= n; i += 2) {
			if (a[i] == val) {v.push_back(i); reverse(a + 1, a + i + 1); break;}
		}
		for (int i = 1; i < n; i += 2) {
			if (a[i + 1] == val - 1) {v.push_back(i); reverse(a + 1, a + i + 1); break;}
		}
		v.push_back(val); reverse(a + 1, a + val + 1);
		for (int i = 1; i <= n; i += 2) {
			if (a[i] == val) {v.push_back(i); reverse(a + 1, a + i + 1); break;}
		}
		v.push_back(val); reverse(a + 1, a + val + 1);
	}
	cout << v.size() << '\n';
	for (int i : v) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k, x;
	cin >> n >> k >> x;
	int cnt = 0;
	int mp[n + 1];
	for (int i = 1; i <= n; i++) {
		mp[i] = -1;
	}
	int it = 1, tot = 0;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		// cout << (i ^ x) << ' ';
		tot ^= i;
		if (1 <= (i ^ x) && (i ^ x) <= n && mp[i] == -1) {
			cnt++; mp[i] = it; mp[i ^ x] = it; it++;
			v.push_back(i);
		}
	}
	// cout << tot << '\n';
	if (k % 2 == 1 && x != tot) {
		cout << "NO\n"; return;
	}
	if (k % 2 == 0 && tot != 0) {
		cout << "NO\n"; return;
	}
	if (it < k) {
		cout << "NO\n"; return;
	}
	vector<int> w;
	for (int i = 1; i <= n; i++) {
		if (mp[i] == -1) {w.push_back(i);}
	}
	cout << "YES\n";
	if (k == 1) {
		cout << n << ' ';
		for (int i = 1; i <= n; i++) {cout << i << ' ';}
		cout << '\n';
		return;
	}
	bool done = false;
	int seen = 0;
	for (int i : v) {
		if (!done) {
			cout << 2 << ' ' << i << ' ' << (i ^ x) << '\n'; seen++;
		}
		else {
			w.push_back(i);
			w.push_back(i ^ x);
		}
		if (seen == k - 1) {done = true;}
	}
	cout << w.size() << ' ';
	for (int i : w) {
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
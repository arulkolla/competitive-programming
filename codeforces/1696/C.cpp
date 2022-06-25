#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<long long, long long>> a, b;	
	for (int i = 0; i < n; i++) {
		long long x; cin >> x;
		long long cnt = 1;
		while (x % k == 0) {cnt *= k; x /= k;}
		if (!a.empty() && a[a.size() - 1].first == x) {
			a[a.size() - 1].second += cnt;
		}
		else {
			a.emplace_back(x, cnt);
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		long long x; cin >> x;
		long long cnt = 1;
		while (x % k == 0) {cnt *= k; x /= k;}
		if (!b.empty() && b[b.size() - 1].first == x) {
			b[b.size() - 1].second += cnt;
		}
		else {
			b.emplace_back(x, cnt);
		}
	}
	if (a.size() != b.size()) {cout << "No\n"; return;}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {cout << "No\n"; return;}
	}
	cout << "Yes\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
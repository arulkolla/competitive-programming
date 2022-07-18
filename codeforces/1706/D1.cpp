#include <bits/stdc++.h>

using namespace std;

const int MAX = 3007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	set<pair<int, pair<int, int>>> s;
	for (int i = 0; i < n; i++) {
		s.insert(make_pair(a[i] / k, make_pair(k, i)));
	}
	int mins = INT_MAX;
	for (int i = 1; i <= k * n; i++) {
		mins = min(mins, (*s.rbegin()).first - (*s.begin()).first);
		auto it = s.begin();
		auto p = (*it);
		if (p.second.first == 1) {break;}
		s.erase(it);
		p.first = a[p.second.second] / (p.second.first - 1);
		p.second.first--;
		s.insert(p);
	}
	mins = min(mins, (*s.rbegin()).first - (*s.begin()).first);
	cout << mins << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
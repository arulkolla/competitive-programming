#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.emplace_back(x, 1);
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.emplace_back(x, 0);
	}
	sort(v.begin(), v.end());
	queue<int> q;
	vector<int> res;
	int lastf = -1;
	for (int i = 0; i < 2 * n; i++) {
		if (v[i].second == 1) {
			q.push(v[i].first);
		}
		else {
			int curr = v[i].first - q.front();
			if (lastf != -1) {curr = v[i].first - lastf;}
			lastf = v[i].first;
			q.pop();
			res.push_back(curr);
		}
		if (q.empty()) {lastf = -1;}
	}
	for (int i : res) {cout << i << ' ';} cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
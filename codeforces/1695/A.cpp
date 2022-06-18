#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	int mx = -MOD;
	pair<int, int> pos;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			if (x > mx) {
				mx = x;
				pos.first = i; pos.second = j;
			}
		}
	}
	cout << (max(abs(pos.first - 0), abs(pos.first - n + 1)) + 1) * (max(abs(pos.second - 0), abs(pos.second - m + 1)) + 1) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
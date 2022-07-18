#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	for (int i = 0; i < m; i++) {
		s += 'B';
	}	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x--;
		int l = min(x, m - 1 - x), r = m - 1 - l;
		if (s[l] == 'B') {s[l] = 'A';}
		else {s[r] = 'A';}
	}
	cout << s << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
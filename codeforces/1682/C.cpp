#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}
	int one = 0, two = 0;
	for (auto p : mp) {
		if (p.second > 1) {two++;}
		else {one++;}
	}
	cout << (one + 1) / 2 + two << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
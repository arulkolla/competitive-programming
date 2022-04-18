#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int dp(vector<int> v, int depth) {
	if (v.empty()) {return 2'000'000'000;}
	vector<int> zero, one;
	for (int i : v) {
		if (i & (1 << depth)) {one.push_back(i);}
		else {zero.push_back(i);}
	}
	int res = 0;
	if (!zero.empty() && !one.empty()) {res += (1 << depth);}
	if (depth == 0) {return res;}
	res += min(dp(zero, depth - 1), dp(one, depth - 1));
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	cout << dp(v, 29);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
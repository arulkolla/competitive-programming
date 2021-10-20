#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long k, b, n, t;
	cin >> k >> b >> n >> t;
	vector<long long> v;
	long long curr = 1;
	v.push_back(curr);
	for (int i = 1; i <= n; i++) {
		curr = curr * k + b;
		v.push_back(curr);
	}
	for (int i = 0; i < n; i++) {
		if (v[i] <= t && t < v[i + 1]) {cout << n - i; return;}
	}
	cout << 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
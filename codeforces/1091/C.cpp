#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			v.push_back(i);
			v.push_back(n / i);
		}
	}
	set<long long> s;
	for (auto x : v) {
		// length is n/x
		// average is (1 + (n + 1) - x)
		s.insert(((long long)(n + 2 - x) * (long long)n) / ((long long)x * 2ll));
	}
	for (auto x : s) {
		cout << x << ' ';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
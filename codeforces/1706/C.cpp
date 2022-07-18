#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	if (n % 2 == 1) {
		long long res = 0;
		for (int i = 1; i < n; i += 2) {
			res += max(0LL, max(a[i + 1], a[i - 1]) - a[i] + 1);
		}
		cout << res << '\n';
	}
	else {
		long long res = LLONG_MAX;
		vector<long long> odds, evens;
		for (int i = 1; i < n - 1; i++) {
			if (i % 2 == 1) {odds.push_back(max(0LL, max(a[i + 1], a[i - 1]) - a[i] + 1));}
			else {evens.push_back(max(0LL, max(a[i + 1], a[i - 1]) - a[i] + 1));}
		}
		reverse(evens.begin(), evens.end());
		vector<long long> op, ep;
		op.push_back(0LL); ep.push_back(0LL);
		for (long long i : odds) {
			op.push_back(op[op.size() - 1] + i);
		}
		for (long long i : evens) {
			ep.push_back(ep[ep.size() - 1] + i);
		}
		reverse(ep.begin(), ep.end());
		for (int i = 0; i < op.size(); i++) {
			res = min(res, op[i] + ep[i]);
		}
		cout << res << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
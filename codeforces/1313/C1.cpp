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
	long long best = -1;
	int besti = 0;
	for (int i = 0; i < n; i++) {
		long long curr = a[i], mn;
		mn = a[i];
		for (int j = i - 1; j >= 0; j--) {
			mn = min(mn, a[j]);
			curr += mn;
		}
		mn = a[i];
		for (int j = i + 1; j < n; j++) {
			mn = min(mn, a[j]);
			curr += mn;
		}
		if (curr > best) {
			best = curr;
			besti = i;
		}
	}
	long long mn = a[besti];
	for (int i = besti - 1; i >= 0; i--) {
		a[i] = min(a[i], mn);
		mn = a[i];
	}
	mn = a[besti];
	for (int i = besti + 1; i < n; i++) {
		a[i] = min(a[i], mn);
		mn = a[i];
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	solve();
}
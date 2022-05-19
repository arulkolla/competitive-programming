#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	long long a[n + 7];
	bool skipped[n + 7];
	pair<long long, long long> b[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		skipped[i] = true;
		b[i] = make_pair(a[i] + i, i);
	}
	sort(b, b + n); 
	for (int i = 0; i < n - k; i++) {
		skipped[b[i].second] = false;
	}
	long long res = 0, curr = 0;
	for (int i = 0; i < n; i++) {
		if (skipped[i]) {curr++;}
		else {res += a[i] + curr;}
	}
	cout << res << '\n'; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}

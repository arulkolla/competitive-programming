#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	pair<long long, long long> a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i].second;
		a[i].first = a[i].second - i;
	}
	sort(a, a + n);
	long long curr = a[0].second, mx = -1;
	for (int i = 1; i < n; i++) {
		if (a[i].first == a[i - 1].first) {curr += a[i].second;}
		else {mx = max(mx, curr); curr = a[i].second;}
	}
	mx = max(mx, curr);
	cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
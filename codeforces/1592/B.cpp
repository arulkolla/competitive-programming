#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (!(i + k >= n && i - k < 0)) {
			v.push_back(a[i]);
			a[i] = -1;
		}
	}
	sort(v.begin(), v.end());
	int pt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == -1) {a[i] = v[pt]; pt++;}
	}
	cout << (is_sorted(a, a + n) ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
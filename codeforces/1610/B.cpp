#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7], b[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	reverse(b, b + n);
	bool bad = false;
	int x1, x2;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			bad = true;
			x1 = a[i];
			x2 = b[i];
		}
	}
	if (!bad) {cout << "YES\n"; return;}
	vector<int> v1, v2;
	for (int i = 0; i < n; i++) {
		if (a[i] != x1) {v1.push_back(a[i]);}
		if (a[i] != x2) {v2.push_back(a[i]);}
	}
	vector<int> v1r = v1, v2r = v2;
	reverse(v1r.begin(), v1r.end());
	reverse(v2r.begin(), v2r.end());
	if (v1 == v1r || v2 == v2r) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
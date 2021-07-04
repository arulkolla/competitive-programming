#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, q;
	cin >> n >> q;
	int a[n + 7];
	vector<int> blank;
	cin >> a[0];
	if (a[0] == 0) {a[0] = 1; blank.push_back(0);}
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) {a[i] = a[i - 1]; blank.push_back(i);}
	}
	int mx = -1;
	for (int i = 0; i < n; i++) {
		mx = max(mx, a[i]);
	}
	if (mx != q) {
		if (blank.empty()) {cout << "NO" << endl; return;}
		else {a[blank[0]] = q;}
	} 
	bool left[q + 7];
	for (int i = 1; i <= q; i++) {
		left[i] = false;
	}
	for (int i = 1; i < n; i++) {
		if (left[a[i]]) {cout << "NO" << endl; return;}
		if (a[i] < a[i - 1]) {left[a[i - 1]] = true;}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
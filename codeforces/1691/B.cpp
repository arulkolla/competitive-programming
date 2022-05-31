#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = i + 1;
	}
	int curr = a[0], pos = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] != curr) {
			rotate(b + pos, b + pos + 1, b + i);
			pos = i;
			curr = a[i];
		}
	}
	rotate(b + pos, b + pos + 1, b + n);
	for (int i = 0; i < n; i++) {
		if (b[i] == i + 1) {cout << -1 << '\n'; return;}
	}
	for (int i = 0; i < n; i++) {
		cout << b[i] << ' ';
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
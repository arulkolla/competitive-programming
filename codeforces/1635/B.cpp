#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	bool mx[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0 || i == n || a[i] <= a[i + 1] || a[i] <= a[i - 1]) {
			mx[i] = false;
		}
		else {
			mx[i] = true;
		}
	}
	int res = 0;
	for (int i = 2; i < n; i++) {
		if (a[i - 1] > a[i - 2] && a[i - 1] > a[i]) {
			a[i] = max(a[i - 1], a[i + 1]);
			res++;
		}
	}
	cout << res << '\n';
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
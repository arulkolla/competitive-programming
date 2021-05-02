#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, x;
	cin >> n >> x;
	int a[n + 7];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum == x) {cout << "NO" << endl; return;}
	cout << "YES" << endl;
	if (sum < x) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
		return;
	}
	int pref = 0;
	for (int i = 0; i < n - 1; i++) {
		pref += a[i];
		if (pref == x) {
			swap(a[i], a[i + 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	if (n < 3) {
		for (int i = 0; i < n; i++) {cout << a[i] << ' ';}
		cout << endl;
		return;
	}
	int mn = MOD, mnindex;
	for (int i = 0; i < n - 1; i++) {
		if (a[i + 1] - a[i] < mn) {
			mn = a[i + 1] - a[i];
			mnindex = i + 1;
		}
	}
	for (int i = mnindex; i < n; i++) {
		cout << a[i] << ' ';
	}
	for (int i = 0; i < mnindex; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long a[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = 0;
	a[n + 1] = 0;
	long long total = 0, ugliness = abs(a[n + 1] - a[n]);
	for (int i = 1; i <= n; i++) {
		ugliness += abs(a[i] - a[i - 1]);
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			total += a[i] - max(a[i - 1], a[i + 1]);
		}
	}
	cout << ugliness - total << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
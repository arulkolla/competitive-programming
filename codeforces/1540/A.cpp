#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long diff[n + 7], sum = 0;
	for (int i = 0; i < n - 1; i++) {
		diff[i] = a[i + 1] - a[i];
		sum += diff[i];
	}
	long long res = -sum;
	for (int i = 0; i < n - 1; i++) {
		res += diff[i] * (i + 1) * (n - 1 - i);
	}
	cout << -res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
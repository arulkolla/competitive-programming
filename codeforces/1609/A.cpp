#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long a[n + 7];
	long long pow2 = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		while (a[i] % 2 == 0) {pow2 *= 2; a[i] /= 2;}
	} 
	sort(a, a + n);
	long long sum = a[n - 1] * pow2;
	for (int i = 0; i < n - 1; i++) {
		sum += a[i];
	}
	cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
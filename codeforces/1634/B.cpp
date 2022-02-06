#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long x, y;
	cin >> n >> x >> y;
	int a[n + 7], odd = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 1) {odd++;}
	}
	if (abs(y - x) % 2 == odd % 2) {cout << "Alice";}
	else {cout << "Bob";}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
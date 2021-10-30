#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long lcms[29] = {1, 1, 2, 6, 12, 60, 60, 420, 840, 2520, 2520, 27720, 27720, 360360, 360360, 360360, 720720, 12252240, 12252240, 232792560, 232792560, 232792560, 232792560, 5354228880, 5354228880, 26771144400, 26771144400, 80313433200};

void solve() {
	int n;
	cin >> n;
	long long a[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= min(n, 26); i++) {
		if (a[i] % lcms[i + 1] == 0) {cout << "NO\n"; return;}
	}
	cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
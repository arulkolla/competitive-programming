#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long prefl[n + 7][n + 7];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			prefl[i][j] = 0LL;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			prefl[i][j] = prefl[i][j - 1] + prefl[i - 1][j] - prefl[i - 1][j - 1] + (a[i] < a[j]);
		}
	}
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 2; j <= n; j++) {
			if (a[i] > a[j]) {
				if (i < 2 || i + 2 > j) {continue;}
				res += prefl[i - 1][j - 1] - prefl[0][j - 1] - prefl[i - 1][i] + prefl[0][i];
			}
		}
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
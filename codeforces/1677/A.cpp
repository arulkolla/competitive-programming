#include <bits/stdc++.h>

using namespace std;

const int MAX = 5007;
const int MOD = 1000000007;

long long prefl[MAX][MAX] = {};

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			prefl[i][j] = prefl[i][j - 1] + prefl[i - 1][j] - prefl[i - 1][j - 1] + (a[i] < a[j]);
		}
	}
	long long res = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = i + 2; j <= n; j++) {
		    res += (prefl[i - 1][j - 1] - prefl[0][j - 1] - prefl[i - 1][i] + prefl[0][i]) * (a[i] > a[j]);
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
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	int lcnt = 0, gcnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 2; j <= n; j++) {
			if (a[i] > a[j]) {gcnt++;}
		}
	}
	vector<vector<long long> > prefl(n + 1, vector<long long>(n + 1));
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
				int l = i, r = j;
				int from_col = l + 1, to_col = r - 1, from_row = 1, to_row = l - 1;
				if (from_row > to_row || from_col > to_col) {continue;}
				res += prefl[to_row][to_col]
						- prefl[from_row - 1][to_col]
						- prefl[to_row][from_col - 1]
						+ prefl[from_row - 1][from_col - 1];
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
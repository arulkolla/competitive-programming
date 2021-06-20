#include <bits/stdc++.h>

using namespace std;

const int MAX = 5007;
const int MOD = 1000000007;

int pref[MAX][MAX] = {};

int prefg(int val, int l, int r) {
	return pref[val][r - 1] - pref[val][l];
}

int prefl(int val, int l, int r) {
	return (r - l - 1) - prefg(val, l, r);
}

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < a[i]; j++) {
			pref[j][i] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			pref[i][j] += pref[i][j - 1];
		}
	}
	// for (int i = 0; i < n; i++) {
		// cout << i << ": ";
		// for (int j = 1; j <= n; j++) {
			// cout << pref[i][j] << ' ';
		// }
		// cout << endl;
	// }
	// - <ai - >aj + >ai + <aj
	int mn = MOD, curr, cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i] > a[j]) {curr = -1;}
			else {curr = 1;}
			mn = min(mn, curr + prefg(a[i], i, j) - prefl(a[i], i, j) + prefl(a[j], i, j) - prefg(a[j], i, j));
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i] > a[j]) {curr = -1;}
			else {curr = 1;}
			if (curr + prefg(a[i], i, j) - prefl(a[i], i, j) + prefl(a[j], i, j) - prefg(a[j], i, j) == mn) {
				cnt++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i] > a[j]) {
				mn++;
			}
		}
	}
	cout << mn << ' ' << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int pref[MAX][27];

void solve() {
	int l, r;
	cin >> l >> r;
	int mn = -1;
	for (int i = 0; i < 27; i++) {
		mn = max(mn, pref[r][i] - pref[l - 1][i]);
	}
	cout << r - l + 1 - mn << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 27; i++) {
    	pref[0][i] = 0;
    }
    for (int i = 1; i < MAX; i++) {
    	int x = i;
    	for (int j = 0; j < 27; j++) {
    		if (x & 1) {pref[i][j] = pref[i - 1][j] + 1;}
    		else {pref[i][j] = pref[i - 1][j];}
    		x >>= 1;
    	}
    }
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}

// Problem: C. Connect Three
// Contest: Codeforces - Technocup 2019 - Elimination Round 4
// URL: https://codeforces.com/contest/1085/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 10007;
const int MOD = 1000000007;

void solve() {
	int x[3], y[3];
	for (int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}
	int mp[MAX];
	for (int i = 0; i < 3; i++) {
		mp[x[i]] = y[i];
	}
	sort(x, x + 3);
	sort(y, y + 3);
	cout << x[2] + y[2] - x[0] - y[0] + 1 << endl;
	for (int i = x[0]; i < x[1]; i++) {
    	cout << i << " " << mp[x[0]] << endl;
    }
    for (int i = x[2]; i > x[1]; i--) {
        cout << i << " " << mp[x[2]] << endl;
    }
    for (int i = y[0]; i <= y[2]; i++) {
        cout << x[1] << " " << i << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
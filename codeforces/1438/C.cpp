
// Problem: C. Engineer Artem
// Contest: Codeforces - Codeforces Round #682 (Div. 2)
// URL: https://codeforces.com/contest/1438/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	int x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			if ((i + j) % 2 == 0) {
				if (x % 2 == 1) {x++;}
			}
			else {
				if (x % 2 == 0) {x++;}
			}
			cout << x << " ";
		}
		cout << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
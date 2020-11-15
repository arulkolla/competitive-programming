
// Problem: B. Numbers Box
// Contest: Codeforces - Codeforces Round #683 (Div. 2, by Meet IT)
// URL: https://codeforces.com/contest/1447/problem/B
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
	long long x, cnt = 0, z = 0;
	long long sum = 0, mn = MOD;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			sum += abs(x);
			mn = min(mn, abs(x));
			if (x < 0) {cnt++;}
			else if (x == 0) {z++;}
		}
	}
	//cout << sum << " " << mn << " " << cnt << " " << z << " ";
	if (cnt % 2) {
		if (z == 0) {
			sum -= 2 * abs(mn);
		}
	}
	cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
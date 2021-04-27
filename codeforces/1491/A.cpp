#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, q;
	cin >> n >> q;
	int a[n + 7], one = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) {one++;}
	}
	int v, k;
	for (int i = 0; i < q; i++) {
		cin >> v >> k;
		if (v == 1) {
			if (a[k] == 0) {one++; a[k] = 1;}
			else {one--; a[k] = 0;}
		}
		else {
			if (k > one) {cout << 0 << endl;}
			else {cout << 1 << endl;}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
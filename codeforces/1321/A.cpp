#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7], b[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int acnt = 0, bcnt = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1 && b[i] == 0) {acnt++;}
		if (a[i] == 0 && b[i] == 1) {bcnt++;}
	}
	if (acnt == 0) {cout << -1 << endl;}
	else {cout << ((bcnt + acnt - 1) / acnt);}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
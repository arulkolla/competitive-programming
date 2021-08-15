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
	int mnpos = n + 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {mnpos = i; break;}
	}
	for (int i = 1; i < mnpos; i++) {
		cout << i << ' ';
	}
	cout << n + 1 << ' ';
	for (int i = mnpos; i <= n; i++) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
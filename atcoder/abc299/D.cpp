#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int l = 1, r = n;
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		cout << "? " << m << endl;
		int resp;
		cin >> resp;
		if (resp == 0) {
			l = m;
		}
		else {
			r = m;
		}
	}
	cout << "! " << l << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	solve();
}
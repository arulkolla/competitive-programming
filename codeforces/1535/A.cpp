#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int a[4], b[4];
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + 4);
	int l, m;
	for (int i = 0; i < 4; i++) {
		if (a[i] == b[3]) {l = i;}
		if (a[i] == b[2]) {m = i;}
	}
	if ((m == 0 && l == 1) || (m == 1 && l == 0) || (m == 2 && l == 3) || (m == 3 && l == 2)) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
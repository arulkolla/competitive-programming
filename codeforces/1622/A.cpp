#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int l[3], p = 0;
	for (int i = 0; i < 3; i++) {
		cin >> l[i];
		p += l[i];
	}
	if (p % 2 == 1) {cout << "NO\n"; return;}
	sort(l, l + 3);
	if (l[2] == l[0] + l[1]) {cout << "YES\n"; return;}
	for (int i = 0; i < 3; i++) {
		if (l[i] == l[(i + 1) % 3] && l[(i + 2) % 3] % 2 == 0) {cout << "YES\n"; return;}
	}
	cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
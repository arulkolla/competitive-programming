#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	string s;
	cin >> s;
	int bal = 0;
	for (char c : s) {
		if (c == 'B') {bal++;}
		else {bal--;}
	}
	cout << (bal == 0 ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
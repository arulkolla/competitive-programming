#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	string s;
	cin >> s;
	int x;
	cin >> x;
	if (s == "ABC") {
		cout << (x <= 1999 ? "YES" : "NO");
	}
	else if (s == "ARC") {
		cout << (x <= 2799 ? "YES" : "NO");
	}
	else if (s == "AGC") {
		cout << (x >= 1200 ? "YES" : "NO");
	}
	else {
		assert(false);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
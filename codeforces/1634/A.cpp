#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string t = s;
	reverse(t.begin(), t.end());
	if (s == t) {
		cout << 1 << '\n';
	}
	else {
		if (k == 0) {cout << 1 << '\n';}
		else {cout << 2 << '\n';}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
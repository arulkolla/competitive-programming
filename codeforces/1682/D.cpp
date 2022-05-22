#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int oddcnt = 0;
	for (char c : s) {
		oddcnt += (c == '1');
	}
	if (oddcnt < 2 || oddcnt % 2 == 1) {cout << "NO\n"; return;}
	cout << "YES\n";
	int pos = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0' && s[(i - 1 + n) % n] == '1') {pos = i; break;}
	}
	if (pos == -1) {
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {pos = i; break;}
		}
	}
	if (pos == -1) {
		for (int i = 2; i <= n; i++) {
			cout << "1 " << i << '\n';
		}
		return;
	}
	for (int i = (pos + 1) % n; i != pos; i = (i + 1) % n) {
		if (s[(i - 1 + n) % n] == '0') {
			cout << ((i - 1 + n) % n) + 1 << ' ' << i + 1 << '\n';
		}
		else {cout << pos + 1 << ' ' << i + 1 << '\n';
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
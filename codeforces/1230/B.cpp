#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	if (n == 1) {
		if (k == 0) {cout << s;}
		else {cout << '0';}
		return;
	}
	int mv = 0;
	for (int i = 0; i < n; i++) {
		if (mv >= k) {break;}
		if (i == 0) {
			if (s[i] != '1') {
				s[i] = '1';
				mv++;
			}
		}
		else {
			if (s[i] != '0') {
				s[i] = '0';
				mv++;
			}
		}
	}
	cout << s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
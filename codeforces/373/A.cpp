#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int k;
	cin >> k;
	k *= 2;
	int cnt[10] = {};
	char c;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> c;
			if (c != '.') {
				cnt[(int)c - (int)'0']++;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (cnt[i] > k) {cout << "NO"; return;}
	}
	cout << "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
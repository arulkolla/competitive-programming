#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int k;
	cin >> k;
	int cnt = 0;
	for (int i = 0; i < 2000; i++) {
		if (i % 3 != 0 && i % 10 != 3) {
			cnt++;
			if (cnt == k) {
				cout << i << endl;
				return;
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
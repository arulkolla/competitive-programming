#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	long long cnt[17] = {};
	for (int i = 1; i <= n; i++) {
		if (i % 9 == 0) {
			cnt[9]++;
		}
		else {
			cnt[i % 9]++;
		}
	}
	long long res = 0;
	for (int a = 1; a <= 9; a++) {
		for (int b = 1; b <= 9; b++) {
			for (int c = 1; c <= 9; c++) {
				if (((a * b) - c) % 9 == 0) {
					res += (cnt[a] * cnt[b] * cnt[c]);
				}
			}
		}
	}
	for (long long i = 1; i <= n; i++) {
		res -= n / i;
	}
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
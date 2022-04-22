#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cnt3 = 0, cnt2 = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] == 3) {
			cnt3++;
		}
		else if (a[i] - a[i - 1] == 2) {
			cnt2++;
		}
		else if (a[i] - a[i - 1] > 3) {
			cout << "NO\n"; return;
		}
	}
	if (((cnt2 == 0) && (cnt3 == 0)) || ((cnt2 == 0) && (cnt3 == 1)) || ((cnt2 <= 2) && (cnt3 == 0))) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	if (n % 2 == 0 && m % 2 == 0) {
		cout << (!(k % 2) ? "YES\n" : "NO\n");
	}
	else {
		if (n % 2 == 1) {
			if (k < (m / 2)) {cout << "NO\n"; return;}
			k -= m / 2;
			cout << (!(k % 2) ? "YES\n" : "NO\n");
		}
		else {
			k = (n * m) / 2 - k;
			if (k < (n / 2)) {cout << "NO\n"; return;}
			k -= n / 2;
			cout << (!(k % 2) ? "YES\n" : "NO\n");
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
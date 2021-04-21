#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int pref[MAX] = {};

long long query(int l, int r) {
	return (pref[l - 1] ^ pref[r]); 
}

void solve() {
	int n;
	cin >> n;
	long long a[n + 7];
	pref[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pref[i] = a[i] ^ pref[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		if (query(1, i) == query(i + 1, n)) {
			cout << "YES" << endl; return;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (query(1, i) == query(i + 1, j) && query(i + 1, j) == query(j + 1, n)) {
				cout << "YES" << endl; return;
			}
		}
	}
	cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
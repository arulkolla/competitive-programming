#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 1], last[n + 1], res[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		last[i] = -1;
		res[i] = 0;
	}	
	for (int i = 1; i <= n; i++) {
		if (last[a[i]] == -1) {
			last[a[i]] = (i % 2);
			res[a[i]]++;
		}
		else {
			if (last[a[i]] != (i % 2)) {
				last[a[i]] = (i % 2);
				res[a[i]]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
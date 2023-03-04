#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	cout << 1 << ' ';
	for (int i = 2; i <= n; i++) {
		int l = 1, r = i + 1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (a[mid] >= i + 1 - mid) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		cout << i - l + 1 << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
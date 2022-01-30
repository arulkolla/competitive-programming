#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int x = 1;
	while (x * 2 < n) {x *= 2;}
	for (int i = x; i < n; i++) {
		cout << i << ' ';
	}
	cout << ((n - 1) ^ x) << ' ';
	for (int i = 0; i < x; i++) {
		if (i != ((n - 1) ^ x)) {
			cout << i << ' ';
		}
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
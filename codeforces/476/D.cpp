#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	cout << (6 * n - 1) * k << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cout << (6 * i + j + 1) * k << ' ';
		}
		cout << (6 * i + 5) * k << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
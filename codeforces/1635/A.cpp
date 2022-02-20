#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int x = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		x |= s;
	}
	cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
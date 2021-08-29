#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int a, b;
	cin >> a >> b;
	if (a == b) {
		if (a == 0) {cout << 0;}
		else {cout << 1;}
	}
	else {
		if (abs(a - b) % 2 == 0) {cout << 2;}
		else {cout << -1;}
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
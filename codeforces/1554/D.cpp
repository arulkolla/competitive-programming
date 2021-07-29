#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "o";
	}
	else if (n % 2 == 1) {
		for (int i = 0; i < (n - 2) / 2; i++) {cout << 'o';}
		cout << "rz";
		for (int i = 0; i <= (n - 2) / 2; i++) {cout << 'o';}
	}
	else {
		for (int i = 0; i < (n - 1) / 2; i++) {cout << 'o';}
		cout << "r";
		for (int i = 0; i <= (n - 1) / 2; i++) {cout << 'o';}
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
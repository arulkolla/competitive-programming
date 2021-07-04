#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int ones = 0, twos = 0, a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 1) {ones++;}
		else {twos++;}
	}
	if (ones == 0 || twos == 0) {
		for (int i = 0; i < ones; i++) {cout << 1 << ' ';}
		for (int j = 0; j < twos; j++) {cout << 2 << ' ';}
	} 
	else {
		cout << 2 << ' ' << 1 << ' ';
		for (int i = 0; i < twos - 1; i++) {cout << 2 << ' ';}
		for (int j = 0; j < ones - 1; j++) {cout << 1 << ' ';}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
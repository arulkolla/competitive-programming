#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int a[15] = {2, 8, 32, 128, 512, 2048, 8192, 32768, 131072, 524288, 2097152, 8388608, 33554432, 134217728, 536870912};

void solve() {
	int n;
	cin >> n;
	if (n % 2 == 1) {cout << "Bob" << endl;}
	else {
		for (int i = 0; i < 15; i++) {
			if (a[i] == n) {cout << "Bob" << endl; return;}
		}
		cout << "Alice" << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n;
	cin >> n;
	if (n % 2 == 1) {cout << "Odd" << endl;}
	else if (n % 4 == 0) {cout << "Even" << endl;}
	else {cout << "Same" << endl;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
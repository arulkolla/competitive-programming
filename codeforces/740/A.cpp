#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n, a, b, c;
	cin >> n >> a >> b >> c;
	if (n % 4 == 0) {cout << 0;}
	else if (n % 4 == 1) {cout << min(c, min(a + b, 3 * a));}
	else if (n % 4 == 2) {cout << min(b, min(a, c) * 2);}
	else if (n % 4 == 3) {cout << min(a, min(b + c, 3 * c));}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long a, b, c;
	cin >> a >> b >> c;
	a += ((c - a + b - 1) / b) * b + b;
	cout << a << ' ' << b << ' ' << c << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}

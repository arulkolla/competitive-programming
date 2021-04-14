#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long x, y;
	cin >> x >> y;
	long long res = 0, now;
	for (long long i = 1; i * i < x; i++) {
		now = min(x / i - 1, y);
		if (now - i > 0) {
			res += now - i;
		}
	}	
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
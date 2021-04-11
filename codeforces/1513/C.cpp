#include <bits/stdc++.h>

using namespace std;

const int MAX = 200027;
const int MOD = 1000000007;

vector<long> f(MAX);

void solve() {
	int s, m;
	cin >> s >> m;
	long res = 0;
	while (s > 0) {
		int d = s % 10;
		s /= 10;
		d += m;
		res += f[d];
		res %= MOD;
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i <= 9; i++) {f[i] = 1;}
    for (int i = 10; i < MAX; i++) {f[i] = (f[i-9] + f[i-10]) % MOD;}
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const long long MOD = 998244353ll;

void solve() {
	long long n, m;
	cin >> n >> m;
	long long res[n + m + 7];
	long long part1 = 1;
	res[1] = 1;
	for (long long i = 2; i <= n + m + 1; i++) {
		res[i] = ((MOD - MOD / i) * res[MOD % i]) % MOD;
		part1++;
	}
	part1 = part1 * (res[m + 1]) % MOD;
	long long part2 = 0;
	for (long long i = 1; i <= n; i ++) {
		part2 += res[i];
		part2 %= MOD;
	}
	part2 = part2 * m % MOD;
	part2++;
	cout << (part1 * part2) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
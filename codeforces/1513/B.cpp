#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

vector<long long> f(MAX);

void solve() {
	int n;
	cin >> n;
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int end = a[0];
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == end) {cnt++;}
		else {break;}
	}
	for (int i = 0; i < n; i++) {
		if ((end & a[i]) != end) {cnt = 1;}
	}
	long long ans = f[n - 2];
	ans *= cnt;
	ans %= MOD;
	ans *= (cnt - 1);
	ans %= MOD;
	cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    f[0] = 1ll; for (int i = 1; i < MAX; i++) {f[i] = f[i-1] * i % MOD;}
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
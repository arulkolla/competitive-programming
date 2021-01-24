
// Problem: D - Div Game
// Contest: AtCoder - AtCoder Beginner Contest 169
// URL: https://atcoder.jp/contests/abc169/tasks/abc169_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long f(long long x) {
	return (long long)(floor(sqrt(8 * x + 1) / 2.0 - 0.5));
}

void solve() {
	long long n;
	cin >> n;
	long long res = 0, cnt = 0;
	while (n % 2 == 0) {
		n /= 2;
		cnt++;
	}
	res += f(cnt);
	for (long long i = 3; i * i <= n; i++) {
		cnt = 0;
		while (n % i == 0) {
			n /= i;
			cnt++;
		}
		res += f(cnt);
	}
	if (n != 1) {res++;}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
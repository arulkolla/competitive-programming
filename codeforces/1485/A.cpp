// Problem: A. Add and Divide
// Contest: Codeforces - Codeforces Round #701 (Div. 2)
// URL: https://codeforces.com/contest/1485/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long a, b;
	cin >> a >> b;
	long long temp = a;
	long long res = 0, ans = MOD;
	if (b == 1) {res++; b++;}
	for (long long i = 0; i < 10; i++) {
		long long now = res + i;
		temp = a;
		while (temp > 0) {
			temp /= (b + i);
			now++;
		}
		ans = min(ans, now);
	}
	cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
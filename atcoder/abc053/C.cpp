
// Problem: C - X: Yet Another Die Game
// Contest: AtCoder - AtCoder Beginner Contest 053
// URL: https://atcoder.jp/contests/abc053/tasks/arc068_a
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n;
	cin >> n;
	long long rem = n % 11;
	if (rem == 0) {cout << 2 * (n / 11);}
	else if (rem <= 6) {cout << 2 * (n / 11) + 1;}
	else {cout << 2 * (n / 11) + 2;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
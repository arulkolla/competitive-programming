
// Problem: C - Go Home
// Contest: AtCoder - AtCoder Beginner Contest 056
// URL: https://atcoder.jp/contests/abc056/tasks/arc070_a
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
	cout << ceil( (sqrt(8*n+1)-1)/2 ) ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
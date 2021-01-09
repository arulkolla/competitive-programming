
// Problem: C - Duodecim Ferra
// Contest: AtCoder - AtCoder Beginner Contest 185
// URL: https://atcoder.jp/contests/abc185/tasks/abc185_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long f(long long n, long long k)  { 
    long long res = 1; 
    if (k > n - k) {k = n - k;}
    for (int i = 0; i < k; ++i) { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
    return res; 
} 

void solve() {
	long long n;
	cin >> n;
	cout << f(n-1, 11);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
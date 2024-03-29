
// Problem: A. XORwice
// Contest: Codeforces - Codeforces Round #676 (Div. 2)
// URL: https://codeforces.com/contest/1421/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long a, b;
	cin >> a >> b;
	long c = a, d = b;
	long val = 0, x = 0; 
    while (a || b) {  
        if ((a & 1) && (b & 1)) { 
            x += (1 << val); 
        } 
        a >>= 1; 
        b >>= 1; 
        val++; 
    } 
	long res = (c ^ x) + (d ^ x);
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
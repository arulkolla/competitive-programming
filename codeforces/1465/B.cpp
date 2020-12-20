
// Problem: B. Fair Numbers
// Contest: Codeforces - Codeforces Round #692 (Div. 2, based on Technocup 2021 Elimination Round 3)
// URL: https://codeforces.com/contest/1465/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

bool check(long long n)  { 
    long long m = n; 
    while (n) { 
        long long r = n % 10; 
        if (r > 0)  
            if ((m % r) != 0) 
                return false;         
        n /= 10; 
    } 
    return true; 
} 

void solve() {
	long long n;
	cin >> n;
	while (!check(n)) {n++;}
	cout << n << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
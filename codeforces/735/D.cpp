
// Problem: D. Taxes
// Contest: Codeforces - Codeforces Round #382 (Div. 2)
// URL: https://codeforces.com/contest/735/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

bool isPrime(long n)  { 
    if (n <= 1) {return false;} 
    if (n <= 3) {return true;}
    if (n % 2 == 0 || n % 3 == 0) {return false;}
    for (int i = 5; i * i <= n; i = i + 6) {
    	if (n%i == 0 || n%(i+2) == 0) {return false;}
    } 
    return true; 
} 

void solve() {
	long n;
	cin >> n;
	if (isPrime(n)) {cout << 1;}
	else {
		if (n % 2) {
			if (isPrime(n - 2)) {cout << 2;}
			else {cout << 3;}
		}
		else {
			cout << 2;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
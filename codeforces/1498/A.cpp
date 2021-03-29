// Problem: A. GCD Sum
// Contest: Codeforces - CodeCraft-21 and Codeforces Round #711 (Div. 2)
// URL: https://codeforces.com/contest/1498/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long gcd(long long a, long long b) {
	if (b == 0) {return a;}
	else {return gcd(b, a % b);}
}

long long f(long long n) {
	long long res = 0;
	while (n != 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

void solve() {
	long long n;
	cin >> n;
	while (true) {
		if (gcd(n, f(n)) > 1) {
			cout << n << endl;
			break;
		}
		n++;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
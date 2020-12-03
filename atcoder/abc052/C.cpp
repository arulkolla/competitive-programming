
// Problem: C - Factors of Factorial
// Contest: AtCoder - AtCoder Beginner Contest 052
// URL: https://atcoder.jp/contests/abc052/tasks/arc067_a
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

bool isPrime(long long n)  { 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
	long long n;
	cin >> n;
	vector<long long> v;
	for (long long i = 2; i <= n; i++) {
		if (isPrime(i)) {v.push_back(i);}
	}
	long long ans = 1;
	for (long long p : v) {
		long long newn = n, res = 0;
		while (newn) {newn /= p; res += newn;}
		// cout << p << " " << res << endl;
		ans *= (res + 1);
		ans %= MOD;
	}
	cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
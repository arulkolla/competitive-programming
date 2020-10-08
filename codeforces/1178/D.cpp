
// Problem: D. Prime Graph
// Contest: Codeforces - Codeforces Global Round 4
// URL: https://codeforces.com/contest/1178/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

bool isPrime(int n)  { 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 

void solve() {
	int n;
	cin >> n;
	if (n == 3) {
		cout << 3 << endl;
		cout << 1 << " " << 2 << endl;
		cout << 2 << " " << 3 << endl;
		cout << 3 << " " << 1 << endl;
	}
	else {
		int cnt, val;
		for (int i = n; i < 999999; i++) {
			if (isPrime(i)) {cnt = i - n; val = i; break;}
		}
		cnt += n;
		cout << cnt << endl;
		for (int i = 0; i < n; i++) {
			cout << (i % n) + 1 << " " << (i + 1) % n + 1 << endl;
		}
		for (int j = 0; j < val - n; j++) {
					cout << (j % n) + 1 << " " << ((j + n/2) % n) + 1 << endl;
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
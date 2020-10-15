
// Problem: D. Almost All Divisors
// Contest: Codeforces - Codeforces Round #560 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1165/D
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
	long long a[MAX];
	bool mp[1000007] = {false};
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]] = true;
	}
	sort(a, a + n);
	long long res = a[0] * a[n - 1];
	for (long long i = 0; i <= n / 2; i++) {
		if (a[i] * a[n - 1 - i] != res) {cout << -1 << endl; return;}
	}
	for (long long i = 1; i <= sqrt(res); i++) { 
        if (res % i == 0 && i != 1 && i != res) { 
        	//cout << i << " " << res/i << " ";
            if (res / i == i) {
            	if (!mp[i]) {cout << -1 << endl; return;}
            } 
            else {
            	if (!mp[i]) {cout << -1 << endl; return;}
            	if (!mp[res/i]) {cout << -1 << endl; return;}
            }
        } 
    } 
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
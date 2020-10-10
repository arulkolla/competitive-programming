
// Problem: A. Avoiding Zero
// Contest: Codeforces - Codeforces Global Round 11
// URL: https://codeforces.com/contest/1427/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 57;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[MAX], sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum == 0) {cout << "NO" << endl;}
	else if (sum < 0) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			if (a[i] < 0) {cout << a[i] << " ";}
		}
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {cout << a[i] << " ";}
		}
		for (int i = 0; i < n; i++) {
			if (a[i] > 0) {cout << a[i] << " ";}
		}
		cout << endl;
	}
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			if (a[i] > 0) {cout << a[i] << " ";}
		}
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {cout << a[i] << " ";}
		}
		for (int i = 0; i < n; i++) {
			if (a[i] < 0) {cout << a[i] << " ";}
		}
		cout << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
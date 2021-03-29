// Problem: D. Genius's Gambit
// Contest: Codeforces - Codeforces Round #704 (Div. 2)
// URL: https://codeforces.com/contest/1492/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int a, b, k;
	cin >> a >> b >> k;
	int tot = a + b - 1; 
	string zero, ones, twos;
	for (int i = 0; i < a; i++) {zero += '0';}
	for (int i = 0; i < b; i++) {ones += '1';}
	ones += zero;
	while (tot - k >= 0 && (ones[tot - k] == '0' || ones[tot] == '1')) {
		tot--;
	}
	twos = ones;
	swap(twos[tot - k], twos[tot]);
	if (tot - k <= 0 && k > 0) {
		cout << "No" << endl; 
	}	
	else {
		cout << "Yes" << endl;
		cout << ones << endl << twos << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
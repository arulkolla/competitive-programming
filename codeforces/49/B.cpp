#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int a, b;
	cin >> a >> b;
	string s;
	s += to_string(a);
	s += to_string(b);
	char mx = '0';
	for (char c : s) {
		mx = max(mx, c);
	}	
	int base = (int)(mx - '0') + 1;
	// cout << base << '\n';
	long long base10 = 0;
	long long pow = 1;
	while (a) {
		base10 += pow * (a % 10);
		a /= 10;
		pow *= base;
	}
	pow = 1;
	while (b) {
		base10 += pow * (b % 10);
		b /= 10;
		pow *= base;
	}
	// cout << base10 << '\n';
	long long pow2 = 1;
	int i = 0;
	while (base10) {
		if (base10 < pow2) {cout << i << '\n'; return;}
		pow2 *= base;
		i++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	solve();
}
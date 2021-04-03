// Problem: C. Balance the Bits
// Contest: Codeforces - Codeforces Round #712 (Div. 2)
// URL: https://codeforces.com/contest/1504/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

char opposite(char c) {
	if (c == '(') {return ')';}
	else {return '(';}
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string a, b;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		a += '!';
		b += '!';
		if (s[i] == '1') {cnt++;}
	}
	if ((cnt % 2 == 1) || (s[0] == '0') || (s[n - 1] == '0')) {
		cout << "NO" << endl;
		return;		
	}
	int rn = 0;
	char prev = ')';
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			if (rn < cnt / 2) {
				a[i] = '(';
				b[i] = '(';
			}
			else {
				a[i] = ')';
				b[i] = ')';
			}	
			rn++;
		}
		else {
			a[i] = opposite(prev);
			b[i] = prev;
			prev = opposite(prev);
		}
	}
	int bala = 0, balb = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '(') {bala++;}
		else {bala--;}
		if (b[i] == '(') {balb++;}
		else {balb--;}
		assert(bala >= 0);
		assert(balb >= 0);
	}
	assert(bala == 0);
	assert(balb == 0);
	cout << "YES" << endl;
	cout << a << endl << b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
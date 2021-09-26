#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (n % 2 == 1 || s[0] == ')' || s[n - 1] == '(') {cout << ":("; return;}
	s[0] = '('; s[n - 1] = ')';
	int left = (n - 2) / 2;
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == '(') {left--;}
	}
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == '?') {
			if (left > 0) {s[i] = '('; left--;}
			else {s[i] = ')';}
		}
	}
	int bal = 0;
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == '(') {bal++;}
		else if (s[i] == ')') {bal--;}
		if (bal < 0) {cout << ":("; return;}
	}
	if (bal != 0) {cout << ":("; return;}
	cout << s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
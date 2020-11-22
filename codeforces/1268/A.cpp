
// Problem: A. Long Beautiful Integer
// Contest: Codeforces - Codeforces Round #609 (Div. 1)
// URL: https://codeforces.com/contest/1268/problem/A
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

string add1(string s, int n) {
	bool end = false;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] != '9') {
			s[i]++;
			end = true;
			break;
		}
		else {
			s[i] = '0';
		}
	}
	if (!end) {
		s.insert(0, "1");
	}
	return s;
}

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string unit = s.substr(0, k);
	string t;
	for (int i = 0; i < n; i++) {
		t.push_back(unit[i % k]);
	}
	if (t < s) {unit = add1(unit, k);}
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cout << unit[i % k];
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
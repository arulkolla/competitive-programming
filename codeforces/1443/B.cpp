
// Problem: B. Saving the City
// Contest: Codeforces - Codeforces Round #681 (Div. 2, based on VK Cup 2019-2020 - Final)
// URL: https://codeforces.com/contest/1443/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	char prev = s[0];
	vector<int> zeroes;
	int curr = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == prev) {curr++;}
		else {
			if (s[i] == '1') {zeroes.push_back(curr); prev = s[i]; curr = 1;}
			else {prev = s[i]; curr = 1;}
		}
	}
	vector<int> good;
	for (int i = 0; i < zeroes.size(); i++) {
		if (i == 0 && s[0] == '0') {}
		else {
			good.push_back(zeroes[i]);
		}
	}
	long long res = a;
	if (good.empty()) {
		if (s[0] != s[s.size() - 1]) {cout << a << endl;}
		else if (s[0] == '1') {cout << a << endl;}
		else {
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '1') {cout << a << endl; return;}
			}	
			cout << 0 << endl;
		}
		return;
	}
	for (int i : good) {
		//cout << i << " ";
		res += min(a, i * b);
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
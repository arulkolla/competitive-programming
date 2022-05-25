#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string s;
	cin >> s;
	int n = s.length();
	int acnt = 0, bcnt = 0;
	for (char c : s) {
		if (c == 'A') {acnt++;}
		if (c == 'B') {bcnt++;}
	}
	if (!(acnt == a + c + d && bcnt == b + c + d)) {cout << "NO\n"; return;}
	string curr = "";
	curr += s[0];
	vector<string> all, imp;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) {curr += s[i];}
		else {all.push_back(curr); curr = ""; curr += s[i];}
	}
	all.push_back(curr);
	int cx = 0, dx = 0, free = 0;
	for (string x : all) {
		if (x.length() % 2 == 1) {
			if (x[0] == 'A') {a--;}
			else {b--;}
			free += x.length() / 2;
		}
		else {imp.push_back(x);}
	}
	if (a < 0 || b < 0 || c < 0 || d < 0) {cout << "NO\n"; return;}
	vector<int> clengths, dlengths;
	for (string x : imp) {
		if (x.length() > 1) {
			if (x[x.length() % 2] == 'A') {cx += (x.length()) / 2; clengths.push_back(x.length() / 2);}
			else {dx += (x.length()) / 2; dlengths.push_back(x.length() / 2);}
			
		}
	}
	sort(clengths.begin(), clengths.end(), greater<int>());
	sort(dlengths.begin(), dlengths.end(), greater<int>());
	int moves = (a + b) / 2;
	
	// cout << cx << ' ' << dx << ' ' << free << '\n';
	// cout << c << ' ' << d << '\n';
	// cout << moves << '\n' << '\n';
	// cout << "cl: "; for (int i : clengths) {cout << i << ' ';} cout << '\n';
	// cout << "dl: "; for (int i : dlengths) {cout << i << ' ';} cout << '\n' << '\n';
	
	int cchange = cx - c, dchange = dx - d;
	if (cchange > 0) {
		int val = 0;
		for (int i = 0; i < min((int)clengths.size(), moves); i++) {
			val += clengths[i];
		}
		if (val >= abs(cchange)) {cout << "YES\n";}
		else {cout << "NO\n";}
	}
	else if (dchange > 0) {
		int val = 0;
		for (int i = 0; i < min((int)dlengths.size(), moves); i++) {
			val += dlengths[i];
		}
		if (val >= abs(dchange)) {cout << "YES\n";}
		else {cout << "NO\n";}
	}
	else {cout << "YES\n";}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
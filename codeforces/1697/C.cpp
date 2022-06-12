#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int scnt[3] = {}, tcnt[3] = {};
	vector<pair<string, string>> v;
	string scurr = "", tcurr = "";
	for (int i = 0; i < n; i++) {
		scurr += s[i]; tcurr += t[i];
		scnt[s[i] - 'a']++; tcnt[t[i] - 'a']++;
		bool ok = true;
		for (int j = 0; j < 3; j++) {if (scnt[j] != tcnt[j]) {ok = false;}}
		if (ok) {
			v.emplace_back(scurr, tcurr);
			scurr = ""; tcurr = "";
			for (int j = 0; j < 3; j++) {scnt[j] = 0; tcnt[j] = 0;}
		}
	}
	bool ok = true;
	if (scurr.length() != 0) {
		for (int j = 0; j < 3; j++) {if (scnt[j] != tcnt[j]) {ok = false;}}
		if (ok) {v.emplace_back(scurr, tcurr);}
	}
	if (!ok) {cout << "NO\n"; return;}
	for (auto p : v) {
		string x = p.first, y = p.second;
		bool seen[3] = {};
		for (char c : x) {
			seen[c - 'a'] = true;
		}
		bool ok = false;
		if (!seen[1]) {
			if (x != y) {cout << "NO\n"; return;}
			else {ok = true;}
		}
		else if (seen[0] && seen[1] && seen[2]) {
			if (x != y) {cout << "NO\n"; return;}
			else {ok = true;}
		}
		if (ok) {continue;}
		if (seen[0] && seen[1]) {
			reverse(x.begin(), x.end());
			reverse(y.begin(), y.end());
			vector<int> posx, posy;
			for (int i = 0; i < x.length(); i++) {
				if (x[i] == 'b') {posx.push_back(i);}
				if (y[i] == 'b') {posy.push_back(i);}
			}
			for (int i = 0; i < posx.size(); i++) {
				if (posx[i] > posy[i]) {cout << "NO\n"; return;}
			}
		}
		else if (seen[1] && seen[2]) {
			vector<int> posx, posy;
			for (int i = 0; i < x.length(); i++) {
				if (x[i] == 'b') {posx.push_back(i);}
				if (y[i] == 'b') {posy.push_back(i);}
			}
			for (int i = 0; i < posx.size(); i++) {
				if (posx[i] > posy[i]) {cout << "NO\n"; return;}
			}
		}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	bool seen[26] = {};
	vector<char> v;
	for (int i = n - 1; i >= 0; i--) {
		if (!seen[(int)s[i] - (int)'a']) {
			v.push_back(s[i]);
			seen[(int)s[i] - (int)'a'] = true;
		} 
	}
	reverse(v.begin(), v.end());
	long long pos[26] = {};
	for (int i = 0; i < (int)v.size(); i++) {
		pos[(int)v[i] - (int)'a'] = (long long)i + 1;
	}
	long long curr = 0;
	string cand;
	for (int i = 0; i < n; i++) {
		curr += pos[(int)s[i] - (int)'a'];
		cand += s[i];
		if (curr == n) {break;}
		if (curr > n) {cout << -1 << '\n'; return;}
	}
	bool ok[26] = {};
	for (char c : v) {ok[(int)c - (int)'a'] = true;}
	int pts = cand.length();
	for (char c : v) {
		int ptcand = 0;
		ok[(int)c - (int)'a'] = false;
		for (int i = 0; i < (int)cand.length(); i++) {
			if (ok[(int)cand[i] - (int)'a']) {
				if (s[pts] != cand[i]) {cout << -1 << '\n'; return;}
				pts++;
			}	
		}
	}
	cout << cand; cout << ' '; for (char c : v) {cout << c;} cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

char flip(char c) {
	if (c == 'R') {return 'B';}
	if (c == 'B') {return 'R';}
	return '?';
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool cseen = false;
	char curr = '?';
	string t = "";
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			if (cseen) {t += curr;}
			else {t += '?';}
		}
		else {
			cseen = true;
			curr = s[i];
			t += s[i];
		}
		curr = flip(curr);
	}
	char last = 'B';
	int pos = n;
	for (int i = 0; i < n; i++) {
		if (t[i] != '?') {last = t[i]; pos = i; break;}
	}
	for (int i = pos - 1; i >= 0; i--) {
		last = flip(last);
		t[i] = last;
	}
	cout << t << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
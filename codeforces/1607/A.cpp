#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int pos[26];
	string alph;
	cin >> alph;
	for (int i = 0; i < 26; i++) {
		pos[alph[i] - 'a'] = i;
	}
	int res = 0;
	string s;
	cin >> s;
	for (int i = 1; i < s.length(); i++) {
		res += abs(pos[s[i] - 'a'] - pos[s[i - 1] - 'a']);
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
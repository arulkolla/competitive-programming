#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int mn = MOD;
	for (char c = 'a'; c <= 'z'; c++) {
		int pos = 0;
		string curr = "";
		int mp[n + 1];
		for (int i = 0; i <= n; i++) {
			mp[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			if (s[i] != c) {curr += s[i]; pos++;}
			else {mp[pos]++;}
		}
		string currr = curr;
		reverse(curr.begin(), curr.end());
		if (currr == curr) {
			int res = 0;
			for (int i = 0; i <= (int)curr.size() / 2; i++) {
				res += max(mp[i], mp[curr.size() - i]) - min(mp[i], mp[curr.size() - i]);
			}
			mn = min(mn, res);
		}
	}
	cout << (mn == MOD ? -1 : mn) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
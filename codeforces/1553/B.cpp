#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	string forw[n + 7], back[n + 7];
	for (int i = 0; i < n; i++) {
		string now = "";
		for (int j = i; j < n; j++) {
			now += s[j];
		}
		forw[i] = now;
		now = "";
		for (int j = i - 1; j >= 0; j--) {
			now += s[j];
		}
		back[i] = now;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (forw[i].substr(0, j - i + 1) + back[j].substr(0, m - (j - i + 1)) == t) {
				cout << "YES" << endl; return;
			}
		}
	}
	cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
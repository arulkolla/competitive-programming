#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int wcnt = n, bcnt = n;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {wcnt--;}
		else {bcnt--;}
	}
	vector<int> v;
	if (bcnt % 2 == 0) {
		for (int i = 1; i < n; i++) {
			if (s[i] == 'W' && s[i - 1] == 'W') {
				v.push_back(i);
				s[i] = 'B';
				s[i - 1] = 'B';
			}
		}
		for (int i = 1; i < n; i++) {
			if (s[i - 1] == 'W') {
				v.push_back(i);
				s[i - 1] = 'B';
				s[i] = (s[i] == 'W' ? 'B' : 'W');
			}
		}
	}
	else if (wcnt % 2 == 0) {
		for (int i = 1; i < n; i++) {
			if (s[i] == 'B' && s[i - 1] == 'B') {
				v.push_back(i);
				s[i] = 'W';
				s[i - 1] = 'W';
			}
		}
		for (int i = 1; i < n; i++) {
			if (s[i - 1] == 'B') {
				v.push_back(i);
				s[i - 1] = 'W';
				s[i] = (s[i] == 'W' ? 'B' : 'W');
			}
		}
	}
	else {
		cout << -1 << endl; return;
	}
	cout << v.size() << endl;
	for (int i : v) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
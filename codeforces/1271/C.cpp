#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	pair<int, int> s;
	cin >> s.first >> s.second;
	pair<int, int> p[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	int uc = 0, lc = 0, dc = 0, rc = 0;
	for (int i = 0; i < n; i++) {
		if (p[i].second > s.second) {uc++;}
		if (p[i].second < s.second) {dc++;}
		if (p[i].first > s.first) {rc++;}
		if (p[i].first < s.first) {lc++;}
	}
	int mx = max(max(lc, rc), max(uc, dc));
	cout << mx << endl;
	if (mx == uc) {
		cout << s.first << ' ' << s.second + 1 << endl;
	}
	else if (mx == dc) {
		cout << s.first << ' ' << s.second - 1 << endl;
	}
	else if (mx == lc) {
		cout << s.first - 1 << ' ' << s.second << endl;
	}
	else if (mx == rc) {
		cout << s.first + 1 << ' ' << s.second << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
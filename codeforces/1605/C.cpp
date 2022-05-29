#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pair<pair<int, int>, pair<int, int> > > v;
	bool ahit = false;
	int bcnt = 0, ccnt = 0;
	int preva;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') {
			if (!ahit) {ahit = true;}
			else {v.push_back(make_pair(make_pair(bcnt, ccnt), make_pair(preva, i)));}
			preva = i;
			bcnt = 0; ccnt = 0;
		}
		else if (s[i] == 'b') {
			bcnt++;
		}
		else {
			ccnt++;
		}
	}
	if (v.empty()) {cout << -1 << '\n'; return;}
	int mn = MOD;
	for (auto p : v) {
		if (p.first.first < 2 && p.first.second < 2) {
			mn = min(mn, p.second.second - p.second.first + 1);
		}
	}
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i].first.first + v[i + 1].first.first < 3 && v[i].first.second + v[i + 1].first.second < 3) {
			mn = min(mn, v[i + 1].second.second - v[i].second.first + 1);
		}
	}
	if (mn == MOD) {cout << -1 << '\n';}
	else {cout << mn << '\n';}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
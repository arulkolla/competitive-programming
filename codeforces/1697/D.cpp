#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	int pos[26] = {}, cnt = 0; 
	for (int i = 0; i <= n; i++) {s += '?';}
	cout << "? 1 1" << endl; 
	char init; cin >> init; if (init == '0') {return;}
	s[1] = init;
	cnt++;
	pos[s[1] - 'a'] = 1;
	for (int curr = 2; curr <= n; curr++) {
		cout << "? 2 1 " << curr << endl;
		int resp; cin >> resp; if (resp == 0) {return;}
		if (resp > cnt) {
			cout << "? 1 " << curr << endl;
			char now; cin >> now; if (now == '0') {return;}
			s[curr] = now;
			pos[s[curr] - 'a'] = curr;
			cnt++;
			continue;
		}
		vector<pair<int, char>> v;
		for (int i = 0; i < 26; i++) {
			if (pos[i] != 0) {v.emplace_back(pos[i], (char)('a' + i));}
		}
		sort(v.begin(), v.end());
		int l = 0, r = v.size();
		while (l + 1 < r) {
			int mid = (l + r) / 2;
			cout << "? 2 " << v[mid].first << ' ' << curr << endl;
			int res; cin >> res; if (res == 0) {return;}
			if (res == v.size() - mid) {
				l = mid;
			}
			else {
				r = mid;
			}
		}
		s[curr] = v[l].second;
		pos[s[curr] - 'a'] = curr;
	}
	s.erase(s.begin());
	cout << "! " << s << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	solve();
}
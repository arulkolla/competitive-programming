#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	pair<int, int> w[m + 7];
	for (int i = 0; i < m; i++) {
		cout << "? ";
		string s;
		for (int j = 0; j < m; j++) {
			if (j == i) {s += '1';}
			else {s += '0';}
		}
		cout << s << endl;
		cin >> w[i].first;
		w[i].second = i;
	}
	sort(w, w + m);
	string curr(m, '0');
	curr[w[0].second] = '1';
	int tot = w[0].first;
	for (int i = 1; i < m; i++) {
		curr[w[i].second] = '1';
		cout << "? " << curr << endl;
		int resp;
		cin >> resp;
		if (resp < tot + w[i].first) {
			curr[w[i].second] = '0';
		}
		else {
			tot += w[i].first;
		}
	}
	cout << "! " << tot << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<string> goods;
	string pref = "", curr;
	for (int i = 0; i < n; i++) {
		pref += s[i];
		curr = pref;
		while (curr.length() < k) {
			curr += pref;
		}
		goods.push_back(curr);
	}
	sort(goods.begin(), goods.end());
	for (int i = 0; i < k; i++) {
		cout << goods[0][i];
	}
	cout << endl;
	// cout << goods[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
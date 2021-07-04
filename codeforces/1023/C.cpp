#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int partner[n + 7];
	stack<int> bal;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {bal.push(i);}
		else {partner[bal.top()] = i; partner[i] = bal.top(); bal.pop();}
	}
	vector<int> goods;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {goods.push_back(i);}
		if (goods.size() >= k / 2) {break;}
	}
	for (int i = k / 2 - 1; i >= 0; i--) {
		goods.push_back(partner[goods[i]]);
	}
	sort(goods.begin(), goods.end());
	for (int i : goods) {cout << s[i];}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
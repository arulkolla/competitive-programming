#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

const string ALPH = "abcdefghijklmnopqrstuvwxyz";

int f(int n, string s, char c, int k) {
	vector<int> v;
	int curr = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == c) {curr++;}
		else if (curr != 0) {v.push_back(curr); curr = 0;}
	}
	if (curr != 0) {v.push_back(curr);}
	// for (int i : v) {cout << i << ' ';} cout << endl;
	if (v.empty()) {return 0;}
	int res = 0;
	for (int i : v) {
		res += (i / k);
	}
	return res;
}

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int mx = 0;
	for (int p = 0; p < 26; p++) {
		mx = max(mx, f(n, s, ALPH[p], k));
	}
	cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
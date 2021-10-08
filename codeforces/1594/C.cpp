#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	char c;
	cin >> n >> c;
	string s;
	cin >> s;
	s = '!' + s;
	vector<int> v;
	bool bad = false, big = false;
	int val;
	for (int i = 1; i <= n; i++) {
		if (s[i] != c) {
			bad = true;
		}
		else {
			if (i >= (n + 2) / 2) {big = true; val = i;}
		}
	}
	if (!bad) {cout << 0 << '\n'; return;}
	else if (big) {
		cout << 1 << '\n';
		cout << val << '\n';
	}
	else {
		cout << 2 << '\n';
		cout << n - 1 << ' ' << n << '\n';
	}
	
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
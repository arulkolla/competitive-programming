#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int curr = 0, mx = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') {curr++;}
		else {
			if (curr == 0 || curr == n) {curr = -1;}
			mx = max(mx, curr); 
			curr = 0;
		}
	}
	if (curr == 0 || curr == n) {curr = -1;}
	mx = max(mx, curr);	
	cout << mx << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	solve();
}
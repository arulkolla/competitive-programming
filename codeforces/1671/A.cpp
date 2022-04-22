#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	string s;
	cin >> s;
	int curr = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == s[i - 1]) {curr++;}
		else {
			if (curr == 1) {cout << "NO\n"; return;}
			curr = 1; 
		}
	}

	if (curr == 1) {cout << "NO\n"; return;}
	else {cout << "YES\n";}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	if (s[0] == 'B' || s[n - 1] == 'A') {cout << "NO\n"; return;}

	int curra = 0, currb = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B') {currb++;}
		else {curra++;}
		
		if ((currb > 0) && ((i + 1 == n) || (s[i + 1] == 'A'))) {
			if (currb > curra) {cout << "NO\n"; return;}
			curra -= currb;
			currb = 0;
		}
	}
	if (currb > 0) {
		if (currb > curra) {cout << "NO\n"; return;}
		curra -= currb;
		currb = 0;
	}
	cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int mnx = 1, mxx = 1, mny = 1, mxy = 1, cx = 1, cy = 1, bx = 1, by = 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'R') {cx++;}
		else if (s[i] == 'L') {cx--;}
		else if (s[i] == 'U') {cy--;}
		else if (s[i] == 'D') {cy++;}
		if (abs(min(mny, cy) - max(mxy, cy)) + 1 > n || abs(min(mnx, cx) - max(mxx, cx)) + 1 > m) {
			cout << 2 - mny << ' ' << 2 - mnx << '\n';
			return;
		}
		mnx = min(mnx, cx); mxx = max(mxx, cx);
		mny = min(mny, cy); mxy = max(mxy, cy);
		bx = abs(mxx - mnx) + 1; by = abs(mxy - mny) + 1;
	}
	cout << 2 - mny << ' ' << 2 - mnx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
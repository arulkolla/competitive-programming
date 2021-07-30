#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	s = '!' + s;
	int pref[n + 7][3];
	pref[0][0] = 0; pref[0][1] = 0; pref[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		if (i <= 3) {
			for (int j = 0; j < 3; j++) {
				if (j == ((int)s[i] - (int)'a')) {pref[i][j] = 1;}
				else {pref[i][j] = 0;}
			}
			
		}
		else {
			for (int j = 0; j < 3; j++) {
				pref[i][j] = pref[i - 3][j];
				if (j == ((int)s[i] - (int)'a')) {pref[i][j]++;}
			}
		}
	}
	
	int l, r;
	string abc = "abc";
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		if (r == l) {cout << 0 << endl; continue;}
		else if (r - l == 1) {cout << (s[l] == s[r] ? 1 : 0) << endl; continue;}
		int r0 = r - r % 3, r1, r2;
		if (r0 + 1 <= r) {r1 = r0 + 1;}
		else {r1 = r0 - 2;}
		if (r1 + 1 <= r) {r2 = r1 + 1;}
		else {r2 = r1 - 2;}
		
		int l0 = ((((l + 3) % 3) == 0) ? l : ((l + 3) - ((l + 3) % 3))), l1, l2;
		if (l0 - 1 >= l) {l2 = l0 - 1;}
		else {l2 = l0 + 2;}
		if (l2 - 1 >= l) {l1 = l2 - 1;}
		else {l1 = l2 + 2;}
		// l0 -= 3;
		// l1 -= 3;
		// l2 -= 3;
		// cout << r0 << ' ' << r1 << ' ' << r2 << endl;
		// cout << l0 << ' ' << l1 << ' ' << l2 << endl;
		// cout << endl;
		int mn = MOD;
		do {
			int val = 0;
			// cout << pref[r0][(int)abc[0] - (int)'a'] - pref[max(0, l0 - 3)][(int)abc[0] - (int)'a'] << endl;
			val += pref[r0][(int)abc[0] - (int)'a'] - pref[max(0, l0 - 3)][(int)abc[0] - (int)'a'];
			// cout << pref[r1][(int)abc[1] - (int)'a'] - pref[max(0, l1 - 3)][(int)abc[1] - (int)'a'] << endl;
			val += pref[r1][(int)abc[1] - (int)'a'] - pref[max(0, l1 - 3)][(int)abc[1] - (int)'a'];
			// cout << pref[r2][(int)abc[2] - (int)'a'] - pref[max(0, l2 - 3)][(int)abc[2] - (int)'a'] << endl;
			val += pref[r2][(int)abc[2] - (int)'a'] - pref[max(0, l2 - 3)][(int)abc[2] - (int)'a'];
			mn = min(mn, r - l + 1 - val);
		} while(next_permutation(abc.begin(), abc.end()));
		cout << mn << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
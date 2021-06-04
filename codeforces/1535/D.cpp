#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int k;
	cin >> k;
	int n = (1 << k);
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	s = '!' + s;
	int a[n + 7];
	int curr = n;
	for (int i = k - 1; i >= 0; i--) {
		for (int j = 0; j < (1 << i); j++) {
			curr--;
			if (i == k - 1) {
				if (s[curr] != '?') {a[curr] = 1;}
				else {a[curr] = 2;}
			}
			else {
				if (s[curr] == '0') {a[curr] = a[curr * 2 + 1];}
				else if (s[curr] == '1') {a[curr] = a[curr * 2];}
				else {a[curr] = a[curr * 2] + a[curr * 2 + 1];}
			}
		}
	}
	// for (int i = 1; i < n; i++) {
		// cout << a[i] << ' ';
	// }
	// cout << endl;
	int q;
	cin >> q;
	int ind;
	char now;
	for (int i = 0; i < q; i++) {
		cin >> ind >> now;
		ind = n - ind;
		s[ind] = now;
		int rn = ind;
		// cout << s << endl;
		if (ind > (1 << (k - 1)) - 1) {
			if (now != '?') {a[ind] = 1;}
			else {a[ind] = 2;}
		}
		else if (now == '0') {
			a[ind] = a[ind * 2 + 1];
		}
		else if (now == '1') {
			a[ind] = a[ind * 2];
		}
		else {
			a[ind] = a[ind * 2] + a[ind * 2 + 1];
		}
		while (rn / 2 > 0) {
			rn /= 2;
			if (s[rn] == '0') {a[rn] = a[rn * 2 + 1];}
			else if (s[rn] == '1') {a[rn] = a[rn * 2];}
			else {a[rn] = a[rn * 2] + a[rn * 2 + 1];}
		}
		cout << a[1] << endl;
		// for (int i = 1; i < n; i++) {
		// cout << a[i] << ' ';
	

	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
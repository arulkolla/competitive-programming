#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (s[0] != '9') {
		for (char c : s) {
			cout << ('9' - c);
		}
		cout << '\n';
	}
	else {
		string t;
		for (char c : s) {
			t += (char)('0' + ('9' - c));
		}
		reverse(t.begin(), t.end());
		bool carry = false;
		for (int i = 0; i < n; i++) {
			if (t[i] == '9') {
				if (carry) {t[i] = '1';}
				else {t[i] = '0';}
				carry = true;
			}
			else if (t[i] == '8') {
				if (carry) {t[i] = '0'; carry = true;}
				else {t[i] = '9'; carry = false;}
			}
			else {
				t[i]++;
				if (carry) {t[i]++;}
				carry = false;
			}
		}
		for (int i = 0; i < n; i++) {
			if (t[i] == '9') {t[i] = '0';}
			else {t[i]++; break;}
		}
		reverse(t.begin(), t.end());
		cout << t << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
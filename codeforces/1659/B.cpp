#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int f[n + 7];
	for (int i = 0; i < n; i++) {
		f[i] = 0;
	}
	if (k % 2 == 1) {
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {k--; f[i] = 1;}
			if (k <= 0) {break;}
		}
		if (k > 0) {f[n - 1] += k;}
		string t;
		for (int i = 0; i < n; i++) {
			if (f[i] % 2 == 0) {
				t += (s[i] == '1' ? '0' : '1');
			}
			else {
				t += s[i];
			}
		}
		cout << t << '\n';
		for (int i = 0; i < n; i++) {
			cout << f[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = 0; i < n; i++) {
			if (k <= 0) {break;}
			if (s[i] == '0') {k--; f[i] = 1;}
		}
		if (k > 0) {f[n - 1] += k;}
		string t;
		for (int i = 0; i < n; i++) {
			if (f[i] % 2 == 1) {
				t += (s[i] == '1' ? '0' : '1');
			}
			else {
				t += s[i];
			}
		}
		cout << t << '\n';
		for (int i = 0; i < n; i++) {
			cout << f[i] << ' ';
		}
		cout << '\n';
	}
	
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
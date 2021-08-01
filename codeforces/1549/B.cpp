#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s;
	cin >> t;
	int cnt = 0, forw = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0' && t[i] == '1') {
			t[i] = '0'; forw++;
		}
	}
	for (int i = 0; i < n; i++) {
		bool good = false;
		if (t[i] == '1') {
			if (i > 0) {
				if (s[i - 1] == '1') {s[i - 1] = '0'; good = true;}
			}
			if (!good && i < n - 1) {
				if (s[i + 1] == '1') {s[i + 1] = '0'; good = true;}
			}
			if (good) {cnt++;}
		}
		
	}
	cout << cnt + forw << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
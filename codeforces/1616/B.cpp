#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string res = "";
	bool same = false;
	for (char c : s) {
		if (res.length() == 0 || c < res[res.length() - 1]) {res += c;}
		else if (c == res[res.length() - 1]) {
			if (same) {
				res += c;
			}
			else {
				break;
			}
		}
		else {break;}
		
		if (res[res.length() - 1] != res[0]) {same = true;}
	}
	cout << res;
	reverse(res.begin(), res.end());
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
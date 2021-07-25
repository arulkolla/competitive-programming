#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string t = s;
	sort(s.begin(), s.end());
	int cnt = n;
	for (int i = 0; i < n; i++) {
		if (s[i] == t[i]) {cnt--;}
	}
	cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}

// Problem: A. Divisible by Seven
// Contest: Codeforces - Codeforces Round #221 (Div. 1)
// URL: https://codeforces.com/problemset/problem/375/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int arr[7] = {1869,1968,1689,6891,1698,9168,1896};

void solve() {
	string s;
	cin >> s;
	int cnt[10] = {};
	for (char c : s) {
		cnt[c - '0']++;
	}
	cnt[1]--; cnt[6]--; cnt[8]--; cnt[9]--;
	string news;
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			news += ('0' + i);
		}
	}
	long long pow = 1;
	long long mod = 0;
	for (int i = news.size() - 1; i >= 0; i--) {
		long long curr = news[i] - '0';
		curr *= pow;
		curr %= 7;
		mod += curr;
		mod %= 7;
		pow *= 10;
		pow %= 7;
	}
	mod *= 4;
	mod %= 7;
	mod = 7 - mod;
	if (mod == 7) {mod = 0;}
	cout << news;
	cout << arr[mod];
	for (int i = 0; i < cnt[0]; i++) {
		cout << 0;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
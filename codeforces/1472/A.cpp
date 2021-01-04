
// Problem: A. Cards for Friends
// Contest: Codeforces - Codeforces Round #693 (Div. 3)
// URL: https://codeforces.com/contest/1472/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long w, h;
	cin >> w >> h;
	long long n;
	cin >> n;
	long long cnt1 = 1, cnt2 = 1;
	while (w % 2 == 0) {
		w /= 2;
		cnt1 *= 2;
	}
	while (h % 2 == 0) {
		h /= 2;
		cnt2 *= 2;
	}
	//cout << cnt1 << " " << cnt2 << endl;
	if (cnt1 * cnt2 >= n) {cout << "YES" << endl;}
	else {cout << "NO" << endl;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}

// Problem: C. Hamburgers
// Contest: Codeforces - Codeforces Round #218 (Div. 2)
// URL: https://codeforces.com/problemset/problem/371/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long cnt[3] = {}, have[3], price[3], r;

bool check(long long k) {
	long long res = 0;
	for (int i = 0; i < 3; i++) {
		res += price[i] * max(cnt[i] * k - have[i], 0ll);
	}
	return (res <= r);
}
 
void solve() {
	string s;
	cin >> s;
	for (char c : s) {
		if (c == 'B') {cnt[0]++;}
		else if (c == 'S') {cnt[1]++;}
		else if (c == 'C') {cnt[2]++;}
		else {cnt[2] = 1 / 0;}
	}
	for (int i = 0; i < 3; i++) {cin >> have[i];}
	for (int i = 0; i < 3; i++) {cin >> price[i];}
	cin >> r;
	
	long long l = 0, r = 2000000000007;
	while (r > l + 1) {
		long long mid = (l + r) / 2;
		if (check(mid)) {l = mid;}
		else {r = mid;}
	}
	
	cout << l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
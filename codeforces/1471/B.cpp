
// Problem: B. Strange List
// Contest: Codeforces - Codeforces Round #694 (Div. 2)
// URL: https://codeforces.com/contest/1471/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long x;
	cin >> n >> x;
	long long res = 0, cnt = 0, v, temp;
	vector<long long> cnts, a;
	for (int i = 0; i < n; i++) {
		cin >> v;
		temp = v;
		cnt = 1;
		while (v % x == 0) {v /= x; cnt++;}
		cnts.push_back(cnt);
		a.push_back(temp);
	}
	long long mn = cnts[0], mni = 0;
	for (int i = 0; i < n; i++) {
		if (cnts[i] < mn) {
			mn = cnts[i];
			mni = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i < mni) {res += (a[i] * (mn + 1));}
		else {res += (a[i] * mn);}
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
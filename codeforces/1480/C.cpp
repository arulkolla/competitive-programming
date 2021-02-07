
// Problem: C. Searching Local Minimum
// Contest: Codeforces - Codeforces Round #700 (Div. 2)
// URL: https://codeforces.com/contest/1480/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int n;

int query(int x) {
	cout << "? " << x << endl;
	int res;
	cin >> res;
	return res;
}

void answer(int x) {
	cout << "! " << x << endl; 
}

void findit(int l, int r) {
	int mid = l + (r - l) / 2;
	int res = query(mid), resl = MOD, resr = MOD;
	if (mid - 1 >= 1) {resl = query(mid - 1);}
	if (mid + 1 <= n) {resr = query(mid + 1);}
	if (res < resl && res < resr) {answer(mid); return;}
	else if (res > resl) {return findit(l, mid - 1);}
	else {return findit(mid + 1, r);}
}

void solve() {
	cin >> n;
	int l = 1, r = n;
	findit(l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}

// Problem: C. Sequence Transformation
// Contest: Codeforces - Codeforces Round #686 (Div. 3)
// URL: https://codeforces.com/contest/1454/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (v.empty() || k != v.end()[-1]) {v.push_back(k);}
	}
	
	int cnt[n + 7];
	for (int i = 1; i <= n; i++) {cnt[i] = 0;}
	
	for (int i : v) {cnt[i]++;}
	cnt[v[0]]--; cnt[v.end()[-1]]--;
	
	int mn = MOD;
	for (int i : v) {mn = min(mn, cnt[i]);}
	cout << mn + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
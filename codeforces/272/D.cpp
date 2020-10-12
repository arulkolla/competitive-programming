
// Problem: D. Dima and Two Sequences
// Contest: Codeforces - Codeforces Round #167 (Div. 2)
// URL: https://codeforces.com/contest/272/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	map<int, map<int, int> > mp;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		mp[k][i + 1]++;
	}
	for (int i = 0; i < n; i++) {
		cin >> k;
		mp[k][i + 1]++;
	}
	int mod;
	cin >> mod;
	long long res = 1;
	for (auto val : mp){
		int tot = 0, cnt = 0;
		for (auto i : val.second) {
			tot += i.second;
			if (i.second == 2) {cnt++;}
		}
		long long curr = 1;
		for (int i = 1; i <= tot; i++) {
			if (i % 2 == 0 && cnt > 0) {
				curr = curr * (i / 2) % mod;
				cnt--;
			}
			else {
				curr = curr * i % mod;	
			}
		}
		res = res * curr % mod;
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
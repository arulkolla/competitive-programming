
// Problem: D. Relatively Prime Graph
// Contest: Codeforces - Educational Codeforces Round 47 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1009/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long gcd(long long a, long long b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

void solve() {
	long long m, n;
	cin >> m >> n;
	if (n + 1 < m) {cout << "Impossible"; return;}
	vector<pair<long long, long long> > res;
	bool done = false;
	for (long long i = 1; i <= m; i++) {
		for (long long j = i + 1; j <= m; j++) {
			if (gcd(i, j) == 1) {res.push_back(make_pair(i, j));}
			if (res.size() == n) {done = true; break;}
		}
		if (done) {break;}
	}
	if (!done) {cout << "Impossible"; return;}
	else {
		cout << "Possible" << endl;
		for (pair<long long, long long> p : res) {
			cout << p.first << " " << p.second << endl;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
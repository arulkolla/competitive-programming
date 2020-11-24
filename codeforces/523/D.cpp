
// Problem: D. Statistics of Recompressing Videos
// Contest: Codeforces - VK Cup 2015 - Qualification Round 2
// URL: https://codeforces.com/contest/523/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n, k;
	cin >> n >> k;
	priority_queue<long long> p;
	for (long long i = 0; i < k; i++) {p.push(0);}
	long long s, m;
	for (long long i = 0; i < n; i++) {
		cin >> s >> m;
		long long temp = max(s, -p.top()) + m;
		cout << temp << endl;
		p.pop(); p.push(-temp);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
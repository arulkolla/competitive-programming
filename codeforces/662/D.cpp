
// Problem: D. International Olympiad
// Contest: Codeforces - CROC 2016 - Final Round [Private, For Onsite Finalists Only]
// URL: https://codeforces.com/problemset/problem/662/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	char a, b, c, d;
	string s;
	cin >> a >> b >> c >> d >> s;
	long long cnt = 0, mul = 10;
	long long n = stoll(s);
	for (int i = 1; i < s.size(); i++) {
		cnt += mul;
		mul *= 10;
	}
	while (n < 1989 + cnt) {
		n += mul;
	}
	cout << n << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
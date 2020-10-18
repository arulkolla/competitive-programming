
// Problem: C. Palindromifier
// Contest: Codeforces - Codeforces Round #676 (Div. 2)
// URL: https://codeforces.com/contest/1421/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	string s;
	cin >> s;
	cout << 3 << endl;
	int n = s.size();
	cout << 'L' << " " << 2 << endl;
	n++;
	cout << 'R' << " " << 2 << endl;
	n += n - 2;
	cout << 'R' << " " << n - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
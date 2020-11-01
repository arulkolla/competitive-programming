
// Problem: B. Elimination
// Contest: Codeforces - Codeforces Round #680 (Div. 2, based on Moscow Team Olympiad)
// URL: https://codeforces.com/contest/1445/problem/B
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << max(a+b, c+d) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
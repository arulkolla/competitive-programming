
// Problem: C - Back and Forth
// Contest: AtCoder -  AtCoder Beginner Contest 051
// URL: https://atcoder.jp/contests/abc051/tasks/abc051_c
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	tx -= sx; ty -= sy;
	sx = 0; sy = 0;
	for (int i = 0; i < tx; i++) {cout << 'R';}
	for (int i = 0; i < ty; i++) {cout << 'U';}
	for (int i = 0; i < tx; i++) {cout << 'L';}
	for (int i = 0; i < ty; i++) {cout << 'D';}
	cout << 'L';
	for (int i = 0; i <= ty; i++) {cout << 'U';}
	for (int i = 0; i <= tx; i++) {cout << 'R';}
	cout << 'D';
	cout << 'R';
	for (int i = 0; i <= ty; i++) {cout << 'D';}
	for (int i = 0; i <= tx; i++) {cout << 'L';}
	cout << 'U';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
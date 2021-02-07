
// Problem: B. The Great Hero
// Contest: Codeforces - Codeforces Round #700 (Div. 2)
// URL: https://codeforces.com/contest/1480/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long A, B;
	int n;
	cin >> A >> B >> n;
	pair<long long, long long> a[n + 7];
	long long mx = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].second;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		long long num = (a[i].second + A - 1) / A;
		B -= num * a[i].first;
		if (B <= 0 && i < n - 1) {cout << "NO" << endl; return;}
		else if (B <= 0 && i == n - 1) {
			B += a[n - 1].first;
			if (B <= 0) {cout << "NO" << endl; return;}
		}
	}
	cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
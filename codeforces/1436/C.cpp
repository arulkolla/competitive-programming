
// Problem: C. Binary Search
// Contest: Codeforces - Codeforces Round #678 (Div. 2)
// URL: https://codeforces.com/contest/1436/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1007;
const int MOD = 1000000007;



pair<long long, long long> binarySearch(int a[], int n, int x) {
	long long left = 0, right = n, l = 0, r = 0;
	while (left < right) {
		int mid = (left + right) / 2;
		//cout << mid << endl;
		if (a[mid] < x) {l++; left = mid + 1;}
		else if (a[mid] > x) {r++; right = mid;}
		else {left = mid + 1;}
	}
	return make_pair(l, r);
}

void solve() {
	int x, n, p;
	cin >> n >> x >> p;
	int a[MAX];
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	pair<int, int> lvl = binarySearch(a, n, p);
	//cout << lvl.first << " " << lvl.second << endl;
	long long res = 1;
	for (long long i = 1; i <= lvl.first; i++) {
		res *= (x - i);
		res %= MOD;
	}
	for (long long i = 0; i < lvl.second; i++) {
		res *= ((n - x) - i);
		res %= MOD;
	}
	for (long long i = 1; i <= n - 1 - lvl.first - lvl.second; i++) {
		res *= i;
		res %= MOD;
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
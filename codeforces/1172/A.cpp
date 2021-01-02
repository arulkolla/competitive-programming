
// Problem: A. Nauuo and Cards
// Contest: Codeforces - Codeforces Round #564 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1172/A
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int a[MAX], n;

bool check(int k) {
	for (int i = 0; i < n; i++) {
		if (a[i] != 0 && i >= k && a[i] <= i - k + 1) {
			return false;
		}
	}
	return true;
}

bool checkS(int onepos) {
	for (int i = 0; i < onepos; i++) {
		if (a[i] != 0 && a[i] - i <= n - onepos + 1) {
			return false;
		}
	}
	return true;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int onepos = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {onepos = i; break;}
	}
	bool ok = true;
	if (onepos != -1) {
		for (int i = onepos; i < n; i++) {
			if (a[i] != i - onepos + 1) {
				ok = false; break;
			}
		}
	}
	else {
		ok = false;
	}
	if (ok && checkS(onepos)) {
		cout << onepos; return;
	}
	
	int l = -1, r = n + 1;
	while (r > l + 1) {
		int mid = (l + r) / 2;
		if (check(mid)) {r = mid;}
		else {l = mid;}
	}
	cout << n + r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
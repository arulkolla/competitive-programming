#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int curr = 0;
	while (k > 0 && curr < n) {
		if (a[curr] > 0) {a[curr]--; a[n - 1]++; k--;}
		else {curr++;}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
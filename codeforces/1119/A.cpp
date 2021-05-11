#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int c[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	int l, r;
	l = 0, r = n - 1;
	while (c[l] == c[r]) {r--;}
	int dist = abs(l - r);
	l = 0, r = n - 1;
	while (c[l] == c[r]) {l++;}
	dist = max(dist, abs(l - r));
	cout << dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
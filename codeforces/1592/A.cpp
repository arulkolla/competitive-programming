#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, h;
	cin >> n >> h;
	int a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, greater<int>());
	int cnt = 2 * (h / (a[0] + a[1])), left = h % (a[0] + a[1]);
	if (left == 0) {cnt += 0;}
	else if (left <= a[0]) {cnt += 1;}
	else {cnt += 2;}
	cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
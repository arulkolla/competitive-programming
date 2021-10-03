#include <bits/stdc++.h>

using namespace std;

const int MAX = 300007;
const int MOD = 1000000007;

int n, a[MAX];

int ok(int i) {
	if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
		return 1;
	}
	if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
		return 1;
	}
	return 0;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = a[1]; a[n + 1] = a[n];
	int mx = 0;
	for (int i = 2; i < n; i++) {
		int v1 = 0, v2 = 0;
		int temp = a[i];
		v1 = ok(i - 1) + ok(i) + ok(i + 1);
		v2 = ok(i - 1) + ok(i) + ok(i + 1);
		a[i] = a[i - 1];
		v1 -= ok(i + 1);
		a[i] = a[i + 1];
		v2 -= ok(i - 1);
		a[i] = temp;
		mx = max(mx, max(v1, v2));
	}
	mx = -mx;
	for (int i = 2; i < n; i++) {
		mx += ok(i);
	}
	cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
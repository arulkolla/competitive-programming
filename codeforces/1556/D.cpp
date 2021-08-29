#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

long long query(long long i, long long j) {
	long long v1, v2;
	cout << "or " << i << ' ' << j << endl;
	cin >> v1;
	cout << "and " << i << ' ' << j << endl;
	cin >> v2;
	return v1 + v2;
}

void solve() {
	int n, k;
	cin >> n >> k;
	long long a[n + 7];
	long long x1 = query(1, 2), x2 = query(2, 3), x3 = query(3, 1);
	a[1] = (x1 + x2 + x3) / 2 - x2;
	a[2] = (x1 + x2 + x3) / 2 - x3;
	a[3] = (x1 + x2 + x3) / 2 - x1;
	long long resp;
	for (int i = 4; i <= n; i++) {
		resp = query(1, i);
		a[i] = resp - a[1];
	}
	sort(a + 1, a + n + 1);
	cout << "finish " << a[k] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
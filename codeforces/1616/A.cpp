#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int res = 0;
	int mp[107];
	for (int i = 0; i <= 100; i++) {
		mp[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (mp[abs(x)] == 0) {mp[abs(x)] = 1; res++;}
		else if (x != 0 && mp[abs(x)] == 1) {mp[abs(x)] = 2; res++;}
	}
	cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
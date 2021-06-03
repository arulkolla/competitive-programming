#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000007;
const int MOD = 1000000007;

bool mp[MAX] = {};

void solve() {
	int n;
	scanf("%d", &n);
	int a[n + 7];
	int pair = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		mp[a[i]] = true;
		if (mp[1000001 - a[i]]) {pair++;}
	}
	vector<int> res;
	int left = n - 2 * pair;
	for (int i = 0; i < n, left > 0; i++) {
		if (!mp[1000001 - a[i]]) {
			left--;
			res.push_back(1000001 - a[i]);
		}
	}
	for (int i = 1; i <= 1000000, pair > 0; i++) {
		if (!mp[i] && !mp[1000001 - i]) {
			pair--;
			res.push_back(i);
			res.push_back(1000001 - i);
		}
	}
	printf("%ld\n", res.size());
	for (int i : res) {
		printf("%d ", i);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
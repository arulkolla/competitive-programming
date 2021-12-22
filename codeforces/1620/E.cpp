#include <bits/stdc++.h>

using namespace std;

const int MAX = 500007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int type[n + 7], x[n + 7], y[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> type[i] >> x[i];
		if (type[i] == 2) {cin >> y[i];}
	}
	int perm[MAX];
	for (int i = 0; i < MAX; i++) {
		perm[i] = i;
	}
	vector<int> res;
	for (int i = n - 1; i >= 0; i--) {
		if (type[i] == 1) {res.push_back(perm[x[i]]);}
		else {perm[x[i]] = perm[y[i]];}
	}
	for_each(res.rbegin(), res.rend(), [](const auto& x) {cout << x << ' ';});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
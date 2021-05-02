#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m, x;
	cin >> n >> m >> x;
	vector<pair<int, int> > v;
	int res[n + 7];
	int thonk;
	for (int i = 0; i < n; i++) {
		cin >> thonk;
		v.push_back(make_pair(thonk, i));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		res[v[i].second] = (i % m) + 1;
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		cout << res[i] << ' ';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
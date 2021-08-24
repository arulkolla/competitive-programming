#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	vector<pair<long long, int> > v;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		long long mx = -1;
		for (int j = 0; j < k; j++) {
			long long a;
			cin >> a;
			a -= j;
			mx = max(mx, a);
		}
		v.emplace_back(mx, k);
	}
	sort(v.begin(), v.end());
	long long psum = 0, res = -1;
	for (int i = 0; i < n; i++) {
		res = max(res, v[i].first - psum);
		psum += v[i].second;
	}
	cout << res + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
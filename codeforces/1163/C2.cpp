#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	map<double, map<double, long long> > mp;
	int n;
	cin >> n;
	pair<int, int> a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double m = (double)(a[i].second - a[j].second) / (a[i].first - a[j].first);
			if (a[i].first == a[j].first) {
				mp[(double)MOD][a[i].first]++;
			}
			else {
				mp[m][a[i].second - m * a[i].first]++;
			}
		}
	}
	long long res = 0, sub = 0;
	for (auto p : mp) {
		long long sum = p.second.size();
		res += p.second.size();
		sub += (sum * (sum - 1)) / 2;
	}
	cout << (res * (res - 1)) / 2 - sub;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
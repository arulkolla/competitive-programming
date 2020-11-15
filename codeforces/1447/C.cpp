
// Problem: C. Knapsack
// Contest: Codeforces - Codeforces Round #683 (Div. 2, by Meet IT)
// URL: https://codeforces.com/contest/1447/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	long long w;
	cin >> n >> w;
	pair<long long, int> a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a, a + n);
	int pos = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i].first <= w) {
			pos = i + 1; break;
		}
	}
	long long sum = 0;
	for (int i = 0; i < pos; i++) {
		sum += a[i].first;
	}
	if (sum < (w + 1) / 2) {
		cout << -1 << endl;
		return;
	}
	if (a[pos - 1].first <= w && (w + 1) / 2 <= a[pos - 1].first) {
		cout << 1 << endl;
		cout << a[pos - 1].second << endl;
	}
	else {
		long long now = 0;
		vector<int> v;
		for (int i = pos - 1; i >= 0; i--) {
			now += a[i].first;
			v.push_back(a[i].second);
			if (now <= w && (w + 1) / 2 <= now) {
				cout << v.size() << endl;
				for (int i : v) {
					cout << i << " ";
				}
				return;
			}
		}
		cout << -1 << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
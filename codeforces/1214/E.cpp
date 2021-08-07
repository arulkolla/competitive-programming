#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	pair<int, int> a[n + 7];
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a, a + n);
	reverse(a, a + n);
	vector<int> good;
	
	good.push_back(a[0].second * 2 - 1);
	for (int i = 1; i < a[0].first; i++) {
		good.push_back(-1);
	}
	good.push_back(a[0].second * 2);
	// for (int i : good) {cout << i << ' ';}
	vector<pair<int, int> > extras;
	for (int i = 1; i < a[0].first; i++) {
		good[i] = a[i].second * 2 - 1;
		if (a[i].first + i >= good.size()) {
			good.push_back(a[i].second * 2);
		}
		else {
			extras.emplace_back(a[i].second * 2, a[i].first + i - 1);
		}
	}
	for (int i = a[0].first; i < n; i++) {
		// cout << "addl: ";
		cout << a[i].second * 2 - 1 << ' ' << good[0] << endl;
		// cout << "addl: ";
		if (a[i].first >= 2) {
			cout << a[i].second * 2 << ' ' << good[a[i].first - 2] << endl;
		}
		else {
			cout << a[i].second * 2 << ' ' << a[i].second * 2 - 1 << endl;
		}
	}
	for (int i = 0; i < good.size() - 1; i++) {
		cout << good[i] << ' ' << good[i + 1] << endl;
	}
	for (auto p : extras) {
		cout << p.first << ' ' << good[p.second] << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
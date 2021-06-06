#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX = 200007;
const int MOD = 10000000007ll;

void solve() {
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	swap(a, b);
	a = -a;
	b = -b;
	pair<pair<int, int>, char> closest[8];
	closest[0] = make_pair(make_pair(a, MOD), 'B');
	closest[1] = make_pair(make_pair(MOD, MOD), 'R');
	closest[2] = make_pair(make_pair(MOD, b), 'B');
	closest[3] = make_pair(make_pair(MOD, -MOD), 'R');
	closest[4] = make_pair(make_pair(a, -MOD), 'B');
	closest[5] = make_pair(make_pair(-MOD, -MOD), 'R');
	closest[6] = make_pair(make_pair(-MOD, b), 'B');
	closest[7] = make_pair(make_pair(-MOD, MOD), 'R');	
	int xi, yi;
	char ci;
	pair<pair<int, int>, char> curr;
	for (int i = 0; i < n; i++) {
		cin >> ci >> xi >> yi;
		swap(xi, yi);
		xi = -xi;
		yi = -yi;
		curr = make_pair(make_pair(xi, yi), ci);
		if (xi == a) {
			if (yi > b) {
				if (yi < closest[0].first.second) {
					closest[0] = curr;
				}
			}
			else {
				if (yi > closest[4].first.second) {
					closest[4] = curr;
				}
			}
		}
		else if (a - b == xi - yi) {
			if (xi + yi > a + b) {
				if (xi + yi < closest[1].first.first + closest[1].first.second) {
					closest[1] = curr;
				}
			}
			else {
				if (xi + yi > closest[5].first.first + closest[5].first.second) {
					closest[5] = curr;
				}
			}
		}
		else if (yi == b) {
			if (xi > a) {
				if (xi < closest[2].first.first) {
					closest[2] = curr;
				}
			}
			else {
				if (xi > closest[6].first.first) {
					closest[6] = curr;
				}
			}
		}
		else if (a + b == xi + yi) {
			if (xi - yi > a - b) {
				if (xi - yi < closest[3].first.first - closest[3].first.second) {
					closest[3] = curr;
				}
			}
			else {
				if (xi - yi > closest[7].first.first - closest[7].first.second) {
					closest[7] = curr;
				}
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		// cout << closest[i].first.first << ' ' << closest[i].first.second << ' ' << closest[i].second << endl;
		if (i % 2 == 0) {
			if (closest[i].second != 'B') {cout << "YES" << endl; return;}
		}
		else {
			if (closest[i].second != 'R') {cout << "YES" << endl; return;}
		}
	}	
	cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
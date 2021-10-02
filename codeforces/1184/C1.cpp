#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	pair<int, int> a[4 * n + 7];
	for (int i = 0; i < 4 * n + 1; i++) {
		cin >> a[i].first >> a[i].second;
	}
	for (int x = 0; x <= 50; x++) {
		for (int y = 0; y <= 50; y++) {
			for (int s = 1; s <= 50; s++) {
				int bad = 0;
				pair<int, int> val;
				for (int i = 0; i < 4 * n + 1; i++) {
					if (!((x <= a[i].first && a[i].first <= x + s && y <= a[i].second && a[i].second <= y + s) && (x == a[i].first || x + s == a[i].first || y == a[i].second || y + s == a[i].second))) {
						bad++;
						val = a[i];
					}
				}	
				if (bad == 1) {cout << val.first << ' ' << val.second; return;}
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, w, h;
	cin >> n >> w >> h;
	pair<int, int> a[n], b[n];
	for (int i = 0; i < n; i++) {
		int ax;
		cin >> ax;
		a[i] = make_pair(ax - w, ax + w);
	}	
	for (int i = 0; i < n; i++) {
		int bx;
		cin >> bx;
		b[i] = make_pair(bx - h, bx + h);
	}
	int d = b[0].first - a[0].first;
	int extra = 0;
	// cout << d << '\n';
	// for (int i = 0; i < n; i++) {
		// cout << a[i].first + d << ' ' << a[i].second + d << ' ';
	// } cout << '\n';
	// for (int i = 0; i < n; i++) {
		// cout << b[i].first << ' ' << b[i].second << ' ';
	// } cout << '\n';
	for (int i = 0; i < n; i++) {
		if (b[i].first < a[i].first + d) {
			extra = max(extra, a[i].first + d - b[i].first);
		}
		else if (a[i].second + d < b[i].second) {
			cout << "NO\n"; return;
		}
	}
	// cout << extra << '\n';
	d -= extra;
	// cout << d << '\n';
	// for (int i = 0; i < n; i++) {
		// cout << a[i].first + d << ' ' << a[i].second + d << ' ';
	// } cout << '\n';
	// for (int i = 0; i < n; i++) {
		// cout << b[i].first << ' ' << b[i].second << ' ';
	// } cout << '\n';
	for (int i = 0; i < n; i++) {
		if (!((a[i].first + d <= b[i].first) && (b[i].second <= a[i].second + d))) {
			cout << "NO\n"; return;	
		}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
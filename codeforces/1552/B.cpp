#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[n + 7][5];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}
	int best = 1;
	for (int i = 2; i <= n; i++) {
		int cnt = 0;
		for (int j = 0; j < 5; j++) {
			if (a[i][j] < a[best][j]) {cnt++;}
		}
		if (cnt >= 3) {best = i;} 
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		if (i != best) {
			for (int j = 0; j < 5; j++) {
				if (a[i][j] < a[best][j]) {cnt++;}
			}
			if (cnt >= 3) {cout << -1 << endl; return;}
		}
	}
	cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int a, b, c, d, e, f, g, h;
	cin >> a >> b >> c >> d >> e >> f >> g >> h;
	if (a > f && d > e && a > h && d > g) {
		cout << "Team 1";
		return;
	}
	if (((e > d && h > a) || (f > a && g > d)) && ((h > c && e > b) || (g > b && f > c))) {
		cout<<"Team 2";
		return;
	}
	if (b > e && c > f && b > g && c > h) {
		cout << "Team 1";
	} 
	else {
		cout << "Draw";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	char c[3][3];
	int xc = 0, oc = 0;
	bool done = true;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> c[i][j];
			if (c[i][j] == 'X') {xc++;}
			else if (c[i][j] == '0') {oc++;}
			else {done = false;}
		}
	}
	bool xwin = false, owin = false;
	for (int i = 0; i < 3; i++) {
		if (c[i][0] == c[i][1] && c[i][1] == c[i][2]) {
			if (c[i][0] == 'X') {xwin = true;}
			if (c[i][0] == '0') {owin = true;}
		}
		if (c[0][i] == c[1][i] && c[1][i] == c[2][i]) {
			if (c[0][i] == 'X') {xwin = true;}
			if (c[0][i] == '0') {owin = true;}
		}
	}
	if (c[0][0] == c[1][1] && c[1][1] == c[2][2]) {
		if (c[0][0] == 'X') {xwin = true;}
		if (c[0][0] == '0') {owin = true;}
	}
	if (c[0][2] == c[1][1] && c[1][1] == c[2][0]) {
		if (c[0][2] == 'X') {xwin = true;}
		if (c[0][2] == '0') {owin = true;}
	}
	if ((xwin && owin) || (xc - oc != 0 && xc - oc != 1) || (xwin && xc - oc == 0) || (owin && xc - oc == 1)) {cout << "illegal";}
	else if (xwin) {cout << "the first player won";}
	else if (owin) {cout << "the second player won";}
	else if (done) {cout << "draw";}
	else if (xc - oc == 0) {cout << "first";}
	else {cout << "second";}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
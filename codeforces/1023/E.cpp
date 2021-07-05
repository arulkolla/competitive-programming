#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

bool send(int r1, int c1, int r2, int c2) {
	cout << "? " << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << endl;
	string s;
	cin >> s;
	assert(s == "YES" || s == "NO");
	if (s == "YES") {return true;}
	else {return false;}
}

void solve() {
	int n;
	cin >> n;
	int x = 1, y = 1;
	bool okr, oku;
	string lt = "";
	for (int i = 0; i < n - 1; i++) {
		// try right
		okr = send(x, y + 1, n, n);
		if (okr) {lt += 'R'; y++;}
		else {lt += 'D'; x++;}
	}
	x = n; y = n;
	string rt = "";
	for (int i = 0; i < n - 1; i++) {
		// try up
		oku = send(1, 1, x - 1, y);
		if (oku) {rt += 'D'; x--;}
		else {rt += 'R'; y--;}
	}
	reverse(rt.begin(), rt.end());
	cout << "! " << lt << rt << endl; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
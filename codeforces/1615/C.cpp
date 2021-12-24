#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	if (a == b) {cout << 0 << '\n'; return;}
	bool obad = true, ebad = true;
	int odd = 0, even = 0;
	int obal = 0, ebal = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			even++;
			if (a[i] == '1') {ebad = false; ebal++;}
			else {ebal--;}
		}
		else {
			odd++;
			if (a[i] == '1') {obad = false; obal++;}
			else {obal--;}
		}
	}
	bool ook = (((odd % 2 == 0) && !obad) && (0 <= obal && obal <= 1)), eok = (((even % 2 == 1) && !ebad) && (0 <= ebal && ebal <= 1));
	if (ook && eok) {cout << min(odd, even) << '\n';}
	else if (ook) {cout << odd << '\n';}
	else if (eok) {cout << even << '\n';}
	else {cout << -1 << '\n';}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
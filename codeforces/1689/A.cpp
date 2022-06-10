#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	string a, b;
	cin >> a >> b;
	string c = "";
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int la = 0, lb = 0, bal = 0;
	while (la < n && lb < m) {
		if (bal == k) {
			c += b[lb]; lb++;
			if (bal > 0) {bal = -1;}
			else {bal--;}
		}
		else if (bal == -k) {
			c += a[la]; la++;
			if (bal < 0) {bal = 1;}
			else {bal++;}
		}
		else if (a[la] < b[lb]) {
			c += a[la]; la++;
			if (bal < 0) {bal = 1;}
			else {bal++;}
		}
		else {
			c += b[lb]; lb++;
			if (bal > 0) {bal = -1;}
			else {bal--;}
		}
	}	
	cout << c << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
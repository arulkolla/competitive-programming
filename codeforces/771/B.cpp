#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

string s = "Kannawoah";

void solve() {
	int n, k;
	cin >> n >> k;
	string a[n + 7];
	int res[n + 7];
	for (int i = 0; i < n - k + 1; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < k - 1; i++) {
		res[i] = i;
	}
	for (int i = k - 1; i < n; i++) {
		if (a[i - k + 1] == "NO") {res[i] = res[i - k + 1];}
		else {res[i] = i;}
	}
	for (int i = 0; i < n; i++) {
		cout << "X";
		while (res[i]) {
			cout << ((res[i] & 1) ? 'x' : 'd');
			res[i] >>= 1;
		}
		cout << ' ';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
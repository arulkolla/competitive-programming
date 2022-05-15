#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int npos, opos;
	int a[n + 1], other[n + 1];
	// other[i] stores position of a[i] + 1
	for (int i = 1; i <= n; i++) {
		other[i] = -1;
	}
	for (int i = 1; i <= n; i++) {
		cout << "? ";
		for (int j = 1; j <= n; j++) {
			if (j != i) {cout << "1 ";}
			else {cout << "2 ";}
		}
		cout << endl;
		int resp;
		cin >> resp;
		if (resp == 0) {npos = i; a[i] = n;}
		else if (resp != i) {other[i] = resp;}
	}
	for (int i = 1; i <= n; i++) {
		cout << "? ";
		for (int j = 1; j <= n; j++) {
			if (j == i) {cout << "1 ";}
			else {cout << "2 ";}
		}
		cout << endl;
		int resp;
		cin >> resp;
		if (resp == 0) {opos = i; a[i] = 1;}
		else if (resp != i) {other[resp] = i;}
	}
	int curr = opos, val = 1;
	while (other[curr] != -1) {
		a[curr] = val;
		curr = other[curr];
		val++;
	}
	cout << "! ";
	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
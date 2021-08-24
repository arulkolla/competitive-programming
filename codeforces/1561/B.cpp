#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int a, b;
	cin >> a >> b;
	int n = a + b;
	set<int> v;
	string s1, s2;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {s1 += '0'; s2 += '1';}
		else {s1 += '1'; s2 += '0';}
	}
	int ones = 0, zeroes = 0, cnt = 0;
	
	ones = n / 2; zeroes = (n + 1) / 2;
	while (!(ones == b && zeroes == a)) {
		cnt++;
		if (ones - b > 0) {ones--; zeroes++;}
		else {ones++; zeroes--;}
	}
	for (int i = cnt; i <= cnt + 2 * min(ones, zeroes); i += 2) {
		v.insert(i);
	}
	
	ones = (n + 1) / 2; zeroes = n / 2; cnt = 0;
	while (!(ones == b && zeroes == a)) {
		cnt++;
		if (ones - b > 0) {ones--; zeroes++;}
		else {ones++; zeroes--;}
	}
	for (int i = cnt; i <= cnt + 2 * min(ones, zeroes); i += 2) {
		v.insert(i);
	}

	cout << v.size() << '\n';
	for (int i : v) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
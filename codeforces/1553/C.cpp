#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	string s1 = s, s2 = s;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			if (s1[i] == '?') {s1[i] = '0';}
			if (s2[i] == '?') {s2[i] = '1';}
		}
		else {
			if (s1[i] == '?') {s1[i] = '1';}
			if (s2[i] == '?') {s2[i] = '0';}
		}
	}
	int res1 = n, res2 = n;
	int curr1 = 0, curr2 = 0, left1 = 5, left2 = 5;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			if (s1[i] == '1') {curr1++;}
			left1--;
		}
		else {
			if (s1[i] == '1') {curr2++;}
			left2--;
		}
		if (curr1 < curr2 && curr1 + left1 < curr2) {
			res1 = i + 1; break;
		}
		if (curr2 < curr1 && curr2 + left2 < curr1) {
			res1 = i + 1; break;
		}
	}
	curr1 = 0, curr2 = 0, left1 = 5, left2 = 5;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			if (s2[i] == '1') {curr1++;}
			left1--;
		}
		else {
			if (s2[i] == '1') {curr2++;}
			left2--;
		}
		if (curr1 < curr2 && curr1 + left1 < curr2) {
			res2 = i + 1; break;
		}
		if (curr2 < curr1 && curr2 + left2 < curr1) {
			res2 = i + 1; break;
		}
	}
	cout << min(res1, res2) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
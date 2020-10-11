
// Problem: D. String Deletion
// Contest: Codeforces - Educational Codeforces Round 96 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1430/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> l;
	int curr = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) {curr++;}
		else {l.push_back(curr); curr = 1;}
	}
	l.push_back(curr);
	// for (int i : l) {cout << i << " ";} cout << endl;
	int i = 0, res = 0, now = 0;
	while (i < l.size()) {
		if (l[i] == 0) {i++;}
		else if (l[i] == 1) {
			while (now <= i || (now < l.size() && l[now] <= 1)) {
				now++;
			}
			if (now == l.size()) {i++; res++; i++;}
			else {l[now]--; res++; i++;}
		}
		else {i++; res++;}
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int gcd(int a, int b) {
	if (b == 0) {return a;}
	return gcd(b, a % b);
}

pair<int, int> f(pair<int, int> p) {
	int g = gcd(p.first, p.second);
	pair<int, int> gp = make_pair(p.first / g, p.second / g);
	return gp;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	pair<int, int> p = make_pair(0, 0);
	map<pair<int, int>, int> mp;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'D') {p.first++;}
		else {p.second++;}
		cout << ++mp[f(p)] << ' ';
	}
	cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}
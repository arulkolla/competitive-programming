#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int match(pair<int, int> a, int k) {
	if (a.first == k) {return a.second;}
	else if (a.second == k) {return a.first;}
	else {return -1;}
}

void solve() {
	pair<int, int> a, b, c;
	int res = 0;
	cin >> a.first >> a.second;
	res += a.first * a.second;
	cin >> b.first >> b.second;
	res += b.first * b.second;
	cin >> c.first >> c.second;
	res += c.first * c.second;
	int sz = -1;
	for (int i = 1; i < 200; i++) {
		if (i * i == res) {sz = i;}
	}
	if (sz == -1) {cout << -1; return;}
	vector<int> goods;
	if (match(a, sz) != -1) {goods.push_back(match(a, sz));}
	if (match(b, sz) != -1) {goods.push_back(match(b, sz));}
	if (match(c, sz) != -1) {goods.push_back(match(c, sz));}
	if (goods.size() != 1 && goods.size() != 3) {cout << -1; return;}
	cout << sz << endl;
	if (goods.size() == 3) {
		char curr = 'A';
		for (int i : goods) {
			for (int j = 0; j < i; j++) {
				for (int k = 0; k < sz; k++) {
					cout << curr;
				}
				cout << endl;
			}
			curr++;
		}
	}
	else {
		if (match(a, sz) != -1) {
			for (int j = 0; j < match(a, sz); j++) {
				for (int k = 0; k < sz; k++) {
					cout << 'A';
				}
				cout << endl;
			}
			int other = sz - match(a, sz);
			int bv = match(b, other);
			for (int j = 0; j < other; j++) {
				for (int k = 0; k < sz; k++) {
					if (k < bv) {cout << 'B';}
					else {cout << 'C';}
				}
				cout << endl;
			}
		}
		else if (match(b, sz) != -1) {
			for (int j = 0; j < match(b, sz); j++) {
				for (int k = 0; k < sz; k++) {
					cout << 'B';
				}
				cout << endl;
			}
			int other = sz - match(b, sz);
			int cv = match(c, other);
			for (int j = 0; j < other; j++) {
				for (int k = 0; k < sz; k++) {
					if (k < cv) {cout << 'C';}
					else {cout << 'A';}
				}
				cout << endl;
			}
		}
		else if (match(c, sz) != -1) {
			for (int j = 0; j < match(c, sz); j++) {
				for (int k = 0; k < sz; k++) {
					cout << 'C';
				}
				cout << endl;
			}
			int other = sz - match(c, sz);
			int av = match(a, other);
			for (int j = 0; j < other; j++) {
				for (int k = 0; k < sz; k++) {
					if (k < av) {cout << 'A';}
					else {cout << 'B';}
				}
				cout << endl;
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
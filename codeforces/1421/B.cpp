
// Problem: B. Putting Bricks in the Wall
// Contest: Codeforces - Codeforces Round #676 (Div. 2)
// URL: https://codeforces.com/contest/1421/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 207;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string a[MAX];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<pair<char, pair<int, int> > > v;
	v.push_back(make_pair(a[0][1], make_pair(1, 2)));
	v.push_back(make_pair(a[1][0], make_pair(2, 1)));
	v.push_back(make_pair(a[n-1][n-2], make_pair(n, n-1)));
	v.push_back(make_pair(a[n-2][n-1], make_pair(n-1, n)));
	if (v[0].first == v[1].first && v[2].first == v[3].first) {
		if (v[0].first == v[2].first) {
			cout << 2 << endl;
			cout << v[0].second.first << " " << v[0].second.second << endl;
			cout << v[1].second.first << " " << v[1].second.second << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	else {
		if (v[0].first - '0' + v[1].first - '0' + v[2].first - '0' + v[3].first - '0' == 3) {
			cout << 1 << endl;
			for (int i = 0; i < 4; i++) {
				if (v[i].first == '0') {
					if (i == 0) {i = 1;}
					else if (i == 1) {i = 0;}
					else if (i == 2) {i = 3;}
					else {i = 2;}
					cout << v[i].second.first << " " << v[i].second.second << endl;
					return;
				}
			}
		}
		else if (v[0].first - '0' + v[1].first - '0' + v[2].first - '0' + v[3].first - '0' == 1) {
			cout << 1 << endl;
			for (int i = 0; i < 4; i++) {
				if (v[i].first == '1') {
					if (i == 0) {i = 1;}
					else if (i == 1) {i = 0;}
					else if (i == 2) {i = 3;}
					else {i = 2;}
					cout << v[i].second.first << " " << v[i].second.second << endl;
					return;
				}
			}
		}
		else {
			//01 01
			cout << 2 << endl;
			for (int i = 0; i < 2; i++) {
				if (v[i].first == '1') {
					cout << v[i].second.first << " " << v[i].second.second << endl;
				}
			}
			for (int i = 2; i < 4; i++) {
				if (v[i].first == '0') {
					cout << v[i].second.first << " " << v[i].second.second << endl;
				}
			}
		}
	}
	//sort(v.begin(), v.end());
	
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
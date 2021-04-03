// Problem: D. 3-Coloring
// Contest: Codeforces - Codeforces Round #712 (Div. 2)
// URL: https://codeforces.com/contest/1504/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void query(int b, int i, int j) {
	cout << b << ' ' << i << ' ' << j << endl;
}

void query(int b, pair<int, int> p) {
	cout << b << ' ' << p.first << ' ' << p.second << endl;
}

void solve() {
	int n;
	cin >> n;
	int a, m1, m2, m3, pos1 = 0, pos2 = 0;
	vector<pair<int, int> > v1, v2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ((i + j) % 2 == 0) {v1.push_back(make_pair(i, j));}
			else {v2.push_back(make_pair(i, j));}
		}
	}
	// decide main 2 colors
	cin >> a;
	if (a != 1) {m1 = 1;}
	else {m1 = 2;}
	query(m1, v1[pos1]);
	pos1++;
	cin >> a;
	int things[3] = {1, 2, 3};
	for (int i = 0; i < 3; i++) {
		if (things[i] != m1 && things[i] != a) {
			m2 = things[i];
			break;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (things[i] != m1 && things[i] != m2) {
			m3 = things[i];
			break;
		}
	}
	query(m2, v2[pos2]);
	pos2++;
	
	int move = n * n - 2;
	while (move >= 1) {
		// chessboard color
		cin >> a;
		if (a != m1 && pos1 < v1.size()) {
			// use first color
			query(m1, v1[pos1]);
			pos1++;
			move--;
		}
		else if (a != m2 && pos2 < v2.size()) {
			// use second color
			query(m2, v2[pos2]);
			pos2++;
			move--;
		}
		else {
			break;
		}
	}
	if (move >= 1) {
		if (pos1 >= v1.size()) {
			// m1 full, fill the rest
			if (a != m2) {
				query(m2, v2[pos2]);
				pos2++;
			}
			else {
				query(m3, v2[pos2]);
				pos2++;
			}
		}
		else {
			// m2 full
			if (a != m1) {
				query(m1, v1[pos1]);
				pos1++;
			}
			else {
				query(m3, v1[pos1]);
				pos1++;
			}
		}
		move--;
	}
	while (move >= 1) {
		cin >> a;
		if (pos1 >= v1.size()) {
			// m1 full, fill the rest
			if (a != m2) {
				query(m2, v2[pos2]);
				pos2++;
			}
			else {
				query(m3, v2[pos2]);
				pos2++;
			}
		}
		else {
			// m2 full
			if (a != m1) {
				query(m1, v1[pos1]);
				pos1++;
			}
			else {
				query(m3, v1[pos1]);
				pos1++;
			}
		}
		move--;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
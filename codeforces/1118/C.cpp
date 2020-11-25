
// Problem: C. Palindromic Matrix
// Contest: Codeforces - Codeforces Round #540 (Div. 3)
// URL: https://codeforces.com/contest/1118/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int cnt[MAX] = {};	
	for (int i = 0; i < n * n; i++) {
		int k; cin >> k;
		cnt[k]++;
	}
	vector<int> v;
	if (n % 2 == 0) {
		for (int i = 1; i <= 1000; i++) {
			if (cnt[i] % 4) {cout << "NO"; return;}
			else {
				for (int j = 0; j < cnt[i] / 4; j++) {
					v.push_back(i);
				}
			}
		}
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int row = i, col = j;
				if (row >= n / 2) {row = n - 1 - row;}
				if (col >= n / 2) {col = n - 1 - col;}
				cout << v[col + n / 2 * row] << " ";
			}
			cout << endl;
		}
	}
	else {
		vector<pair<int, int> > thing[5];
		int a[n + 7][n + 7];
		for (int i = 0; i < (n + 1) / 2; i++) {
			for (int j = 0; j < (n + 1) / 2; j++) {
				if ((i != n - i - 1) && (j != n - j - 1)) {thing[4].push_back(make_pair(i, j));}
				else if ((i != n - i - 1) ^ (j != n - j - 1)) {thing[2].push_back(make_pair(i, j));}
				else {thing[1].push_back(make_pair(i, j));}
			}
		}
	 
		int id = 0;
		vector<int> v;
		v.push_back(4);v.push_back(2);v.push_back(1);
		for (int sz : v) {
			for (pair<int, int> cur : thing[sz]) {
				while (id < MAX && cnt[id] < sz)
					id++;
				if (id == MAX) {
					cout << "NO";
					return;
				}
				cnt[id] -= sz;
				int i = cur.first;
				int j = cur.second;
				a[i][j] = a[i][n - j - 1] = a[n - i - 1][j] = a[n - i - 1][n - j - 1] = id;
			}
			id = 0;
		}
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[j][i] << " ";
			}
			cout << endl;
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
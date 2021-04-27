#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	char a[n + 7][m + 7];
	bool marked[n + 7][m + 7];
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < m; j++) {
	        cin >> a[i][j];
	        marked[i][j] = false;
	    }
	}
	vector<pair<int, int> > v;
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < m; j++) {
	        if (i - 1 >= 0 && i + 1 < n && j - 1 >= 0 && j + 1 < m) {
	            if (a[i - 1][j] == '*' && a[i + 1][j] == '*' && a[i][j - 1] == '*' && a[i][j + 1] == '*') {
	                if (a[i][j] == '*') {
	                    v.push_back(make_pair(i, j));
	                }
	            }
	        }
	    }
	}
	vector<pair<pair<int, int>, int> > res;
	for (auto p : v) {
	    int i = p.first, j = p.second;
	    marked[i][j] = true;
	    int sz = 1;
	    while (true) {
	        if (i - sz < 0 || i + sz >= n || j - sz < 0 || j + sz >= m) {
	            break;
	        }
	        if (a[i - sz][j] != '*' || a[i + sz][j] != '*' || a[i][j - sz] != '*' || a[i][j + sz] != '*') {
	            break;
	        }
	        marked[i - sz][j] = true;
	        marked[i + sz][j] = true;
	        marked[i][j - sz] = true;
	        marked[i][j + sz] = true;
	        sz++;
	    }
	    res.push_back(make_pair(make_pair(i, j), sz));
	}
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*' && !marked[i][j]) {
                cout << -1 << endl; return;
            }
        }
    }	
    cout << res.size() << endl;
    for (auto p : res) {
        cout << p.first.first + 1 << ' ' << p.first.second + 1 << ' ' << p.second - 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
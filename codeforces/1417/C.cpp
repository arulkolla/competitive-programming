// Problem : C. k-Amazing Numbers
// Contest : Codeforces - Codeforces Round #673 (Div. 2)
// URL : https://codeforces.com/contest/1417/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 300007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[MAX];
	vector<int> v[MAX];
	int cnt[MAX];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v[a[i]].push_back(i);
		if (v[a[i]].size() == 1) {
		    cnt[a[i]] = -1;
		}
		else if (v[a[i]].size() >= 2) {
		    cnt[a[i]] = max(v[a[i]][v[a[i]].size() - 1] - v[a[i]][v[a[i]].size() - 2], cnt[a[i]]);
		}
	}
	if (n == 1) {cout << a[0] << endl; return;}
	int dists[MAX] = {};
	for (int i = 1; i <= n; i++) {
		int dist;
		if (!(v[i].empty())) {
			int fnl = v[i][v[i].size() - 1], bgn = v[i][0];
			dist = max(cnt[i], max(bgn - -1, n - fnl));
			if (dists[dist] == 0) {
				dists[dist] = i;
			}
			else {
				dists[dist] = min(dists[dist], i);
			}
			// cout << dist << " " << i << endl;
		}
	}
	int prev;
	bool flag = false;
	for (int i = 1; i <= n; i++) {
	    if (i == 1) {
	        if (dists[i] == 0) {cout << -1; prev = 0;}
		    else {cout << dists[i]; prev = dists[i]; flag = true;}
	    }
		else {
		    if (dists[i] != 0) {
		        if (dists[i] >= prev && prev != 0) {
		            cout << prev; prev = prev; flag = true;
		        }
		        else {
		            cout << dists[i]; prev = dists[i]; flag = true;   
		        }
		    }
		    else {
		        if (flag) {cout << prev; prev = prev; flag = true;}
		        else {cout << -1; prev = 0;}
		    }
		}
		// prev = dists[i];
		cout << " ";
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
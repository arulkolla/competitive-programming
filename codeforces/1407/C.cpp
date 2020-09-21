
// Problem : C. Chocolate Bunny
// Contest : Codeforces - Codeforces Round #669 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1407/C
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
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int query(int a, int b) {
	int c;
	cout << "? " << a << " " << b << endl;
	cin >> c;
	return c;
}

void solve() {
	int n;
	cin >> n;
	int mx = 1;
	int a[MAX];
	for (int i = 2; i <= n; i++) {
		int u, v;
		u = query(mx, i);
		v = query(i, mx);
		if (u < v) {
			a[i - 1] = v;
		}
		else {
			a[mx - 1] = u;
			mx = i;
		}
	}
	a[mx - 1] = n;
	cout << "! ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
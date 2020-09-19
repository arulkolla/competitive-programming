
// Problem : D1. Sage's Birthday (easy version)
// Contest : Codeforces - Codeforces Round #671 (Div. 2)
// URL : https://codeforces.com/contest/1419/problem/D1
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

const int MAX = 100007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int a[MAX];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int val;
	if (n % 2) {cout << n / 2 << endl; val = n / 2;}
	else {cout << (n - 1) / 2 << endl; val = (n - 1) / 2;}
	int res[MAX];
	int curr = 0;
	for (int i = 0; i < n; i++) {
		if (i < val) {
			res[2 * i + 1] = a[i];
		}
		else {
			res[curr] = a[i];
			curr += 2;
		}
	}
	if (n % 2 == 0) {res[n - 1] = a[n - 1];}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}

// Problem : C. Killjoy
// Contest : Codeforces - Codeforces Round #671 (Div. 2)
// URL : https://codeforces.com/contest/1419/problem/C
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

const int MAX = 1007;
const int MOD = 1000000007;

void solve() {
	int n, x;
	cin >> n >> x;
	int t;
	long long sum = 0, count = 0;
	bool all = true;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t != x) {
			all = false;
			sum += x - t;
			count++;
		}
	}
	if (all || count == 0) {cout << 0 << endl;}
	else if (sum == 0 || count != n) {cout << 1 << endl;}
	else {cout << 2 << endl;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}

// Problem : D. Coins and Queries
// Contest : Codeforces - Codeforces Round #494 (Div. 3)
// URL : https://codeforces.com/contest/1003/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

void solve() {
	int n, q;
	cin >> n >> q;
	int cnt[32] = {}, t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		cnt[__builtin_ctz(t)]++;
	}
	for (int i = 0; i < q; i++) {
		cin >> t;
		long long res = 0;
		for (int i = 31; i >= 0; i--) {
			if (t <= 0) {break;}
			res += (long long)min(t >> i, cnt[i]);
			t -= (1 << i) * min(t >> i, cnt[i]);
		}
		if (t > 0) {cout << -1 << endl;}
		else {cout << res << endl;}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
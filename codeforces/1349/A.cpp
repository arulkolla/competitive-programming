
// Problem : A. Orac and LCM
// Contest : Codeforces - Codeforces Round #641 (Div. 1)
// URL : https://codeforces.com/contest/1349/problem/A
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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

const int MAX = 200007;
const int MOD = 1000000007;

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

void solve() {
	int n;
	cin >> n;
	long long a[MAX];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long val = a[0], prev = a[0], gc, lc, res = 0;
	for (int i = 1; i < n; i++) {
		val = a[i];
		gc = gcd(val, prev);
		lc = (val * prev) / gc;
		res = gcd(res, lc);
		prev = gcd(prev, val);
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
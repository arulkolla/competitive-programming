
// Problem : C. Wet Shark and Flowers
// Contest : Codeforces - Codeforces Round #341 (Div. 2)
// URL : https://codeforces.com/problemset/problem/621/C
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

const int MAX = 100007;
const int MOD = 1000000007;

void solve() {
	int n, p;
	cin >> n >> p;
	long double a[MAX];
	int l, r;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		a[i] = (r / p - (l - 1) / p) / (r - l + 1.0L);
	}
	long double res;
	for (int i = 0; i < n; i++) {
		res += 1 - (1 - a[i % n]) * (1 - a[(i + 1) % n]);
	}
	cout << fixed << setprecision(17) << res * 2000 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}

// Problem : B. Diagonal Walking v.2
// Contest : Codeforces - Educational Codeforces Round 50 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1036/problem/B
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

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	long long n, m, k;
	cin >> n >> m >> k;
	if (m > n) {swap(m, n);}
	if ((n - m) % 2) {k--; n--;}
	else if ((n - k) % 2) {k--; n--; m--; k--;}
	if (k < n) {cout << -1 << endl;}
	else {cout << k << endl;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}

// Problem : A. New Year Table
// Contest : Codeforces - Codeforces Round #100
// URL : https://codeforces.com/contest/140/problem/A
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
	long double R, r;
	long long n;
	cin >> n >> R >> r;
	if (r > R) {cout << "NO"; return;}
	if (n == 1) {cout << "YES"; return;}
	if (n == 2 && r * 2 <= R) {cout << "YES"; return;}
	cout << (n * asin(r / (R - r)) <= 3.1415927 ? "YES" : "NO");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
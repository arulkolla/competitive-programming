
// Problem : D. Minimum Diameter Tree
// Contest : Codeforces - Technocup 2019 - Elimination Round 4
// URL : https://codeforces.com/contest/1085/problem/D
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
	int n, s;
	cin >> n >> s;
	int u, v;
	int cnt[MAX] = {0};
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		cnt[u]++;
		cnt[v]++;
	}
	long double res = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 1) {res += 1;}
	}
	cout << fixed << setprecision(17) << (2 * s) / res;
}	

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}

// Problem : B. RPG Protagonist
// Contest : Codeforces - Educational Codeforces Round 94 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1400/problem/B
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
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int p, f;
	cin >> p >> f;
	if (p < f) {swap(p,f);}
	int cnts, s, cntw, w;
	cin >> cnts >> cntw;
	cin >> s >> w;
	if (s > w) {
		swap(s,w);
		swap(cnts,cntw);
	}
	int res = 0;
	for (int i = 0; i <= cnts; i++) {
		if (p < i * s) {break;}
		int t1 = min((p - i * s) / w, cntw);
		int t2 = min(f / s, cnts - i);
		res = max(res, i + t1 + t2 + min((f - t2 * s) / w, cntw - t1));
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
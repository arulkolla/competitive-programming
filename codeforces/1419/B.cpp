
// Problem : B. Stairs
// Contest : Codeforces - Codeforces Round #671 (Div. 2)
// URL : https://codeforces.com/contest/1419/problem/B
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

void solve() {
	long long arr[32] = {1, 7, 35, 155, 651, 2667, 10795, 43435, 174251, 698027, 2794155, 11180715, 44731051, 178940587, 715795115, 2863245995, 11453115051, 45812722347, 183251413675, 733006703275, 2932028910251, 11728119835307, 46912487729835, 187649967696555, 750599904340651, 3002399684471467, 12009598872103595, 48038395756849835, 192153583564270251, 768614335330822827, 3074457343470774955, 3074457343470774955}; 
	long long val;
	cin >> val;
	for (int i = 0; i < 32; i++) {
		if (val < arr[i]) {cout << i << endl; return;}
	}
	cout << 32 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
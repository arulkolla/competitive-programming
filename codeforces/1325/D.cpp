
// Problem : D. Ehab the Xorcist
// Contest : Codeforces - Codeforces Round #628 (Div. 2)
// URL : https://codeforces.com/contest/1325/problem/D
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
	long long u, v;
	cin >> u >> v;
	if (max(u, v) == 0) {
		cout << 0 << endl;
	}
	else if (min(u, v) == max(u, v)) {
		cout << 1 << endl;
		cout << u << endl;
	}
	else if (u - v > 0 || (u - v) % 2) {
		cout << -1 << endl;
	}
	else {
		long long w = (v - u) / 2;
		if ((u + w) == (u ^ w)) {
			cout << 2 << endl;
			cout << u + w << " " << w;
		}
		else {
			cout << 3 << endl;
			cout << u << " " << w << " " << w << endl;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
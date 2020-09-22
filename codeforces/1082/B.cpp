
// Problem : B. Vova and Trophies
// Contest : Codeforces - Educational Codeforces Round 55 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1082/problem/B
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
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> lengths;
	int mx = -1, cnt = 0, curr = 0, prev = 0;
	for (char c : s) {
		if (c == 'G') {cnt++; curr++;}
		else {prev = curr; curr = 0;}
		mx = max(mx, curr + prev + 1);
	}
	cout << min(mx, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
   // int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	solve();
}
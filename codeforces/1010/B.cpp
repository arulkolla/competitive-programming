
// Problem : B. Rocket
// Contest : Codeforces - Codeforces Round #499 (Div. 1)
// URL : https://codeforces.com/contest/1010/problem/B
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

const int MAX = 37;
const int MOD = 1000000007;

int query(int val) {
	cout << val << endl;
	int res;
	cin >> res;
	return res;
}

void solve() {
	int m, n;
	cin >> m >> n;
	int a[MAX];
	for (int i = 0; i < n; i++) {
		a[i] = -query(1);
		if (a[i] == 0) {return;}
		else if (a[i] == 2) {return;}
	}
	int l = 1, r = m, cnt = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		int res = query(mid) * a[cnt];
		if (res == 0) {return;}
		else if (res == 1) {r = mid - 1;}
		else {l = mid + 1;}
		cnt++;
		cnt %= n;
	}
	// query(r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
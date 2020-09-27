
// Problem : A. Copy-paste
// Contest : Codeforces - Codeforces Round #673 (Div. 2)
// URL : https://codeforces.com/contest/1417/problem/A
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
	int n, k;
	cin >> n >> k;
	int a[MAX], mn = 10000000, mnindex;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < mn) {mn = a[i]; mnindex = i;}
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		if (i != mnindex) {res += (k - a[i]) / mn;}
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
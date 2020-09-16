
// Problem : A. Alice and Bob
// Contest : Codeforces - Codeforces Round #201 (Div. 1)
// URL : https://codeforces.com/problemset/problem/346/A
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

const int MAX = 107;
const int MOD = 1000000007;

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

void solve() {
	long long a[MAX];
	int n;
	cin >> n;
	long long first;
	cin >> first;
	long long gc, mx, second;
	cin >> second;
	gc = gcd(first, second);
	mx = max(first, second);
	for (int i = 2; i < n; i++) {
		cin >> second;
		gc = gcd(gc, second);
		mx = max(mx, second);
	}
	cout << ((((mx / gc) - n) % 2) ? "Alice" : "Bob");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}

// Problem : B. Two Arrays
// Contest : Codeforces - Codeforces Round #673 (Div. 2)
// URL : https://codeforces.com/contest/1417/problem/B
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

const int MAX = 100007;
const int MOD = 1000000007;

void solve() {
	int n, t;
	cin >> n >> t;
	int a[MAX];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (t % 2) {
		for (int i = 0; i < n; i++) {
			if (a[i] % 2) {cout << 0;}
			else {cout << 1;}
			cout << " ";
		}
		cout << endl;
	}
	else {
		int last = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < t / 2) {cout << 0;}
			else if (a[i] > t / 2) {cout << 1;}
			else {
				if (last == 0) {cout << 0; last = 1;}
				else {cout << 1; last = 0;}
			}
			cout << " ";
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
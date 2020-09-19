
// Problem : A. Digit Game
// Contest : Codeforces - Codeforces Round #671 (Div. 2)
// URL : https://codeforces.com/contest/1419/problem/A
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
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (n % 2) {
		for (int i = 0; i < s.size(); i++) {
			if (i % 2 == 0) {
				if ((s[i] - '0') % 2 == 1) {
					cout << 1 << endl;
					return;
				}
			}
		}
		cout << 2 << endl;
	}
	else {
		for (int i = 0; i < s.size(); i++) {
			if (i % 2 == 1) {
				if ((s[i] - '0') % 2 == 0) {
					cout << 2 << endl;
					return;
				}
			}
		}
		cout << 1 << endl;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
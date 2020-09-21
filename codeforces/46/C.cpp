
// Problem : C. Hamsters and Tigers
// Contest : Codeforces - School Personal Contest #2 (Winter Computer School 2010/11) - Codeforces Beta Round #43 (ACM-ICPC Rules)
// URL : https://codeforces.com/contest/46/problem/C
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

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int hcount = 0;
	for (char c : s) {
		if (c == 'H') {hcount++;}
	}
	int mn = 1000000007;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < hcount; j++) {
			if (s[(i + j) % n] == 'T') {cnt++;}
		}
		mn = min(mn, cnt);
	}
	cout << mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
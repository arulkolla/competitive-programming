
// Problem : A. Subset Mex
// Contest : Codeforces - Codeforces Round #670 (Div. 2)
// URL : https://codeforces.com/contest/1406/problem/A
// Memory Limit : 512 MB
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

const int MAX = 107;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	int cnt[MAX] = {0}, t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		cnt[t]++;
	}
	int small = 0, big = 0;
	for (int i = 0; i <= 101; i++) {
		if (cnt[i] == 1) {
			small = i; 
			for (int j = i + 1; j <= 101; j++) {
				if (cnt[j] == 0) {
					big = j; break;
				}
			}
			break;
		}
		else if (cnt[i] == 0) {big = i; small = i; break;}
	}
	cout << big + small << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
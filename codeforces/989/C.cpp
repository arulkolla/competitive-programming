
// Problem : C. A Mist of Florescence
// Contest : Codeforces - Codeforces Round #487 (Div. 2)
// URL : https://codeforces.com/problemset/problem/989/C
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
	string s = "ABCD";
	int a[MAX];
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
		a[i]--;
	}
	cout << "32 50" << endl;
    for (int q = 0; q < 4; q++) {
        for (int j = 0; j < 8; j++) {
        	for (int i = 0; i < 50; i++) {
        		if ((i & 1) && (j & 1) && a[q]) {cout << s[q]; a[q]--;}
                else {cout << s[(q + 2) % 4];}		
        	}
        	cout << endl;
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
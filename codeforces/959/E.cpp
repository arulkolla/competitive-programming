
// Problem : E. Mahmoud and Ehab and the xor-MST
// Contest : Codeforces - Codeforces Round #473 (Div. 2)
// URL : https://codeforces.com/contest/959/problem/E
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
	long long n;
	cin >> n;
	n--;
	vector<long long> k;
	while (n >= 1) {
		k.push_back(n);
		n /= 2;
	}
	reverse(k.begin(), k.end());
	long long curr, prev;
	for (long long i : k) {
		if (i == 1) {curr = 1;}
		else if (i % 2) {
			curr = prev * 2 + i / 2 + 1;
		}
		else {
			curr = prev * 2 + i / 2;
		}
		// cout << i << " " << curr << endl;
		prev = curr;
	}
	cout << curr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}

// Problem : B. Alternating Current
// Contest : Codeforces - Codeforces Round #200 (Div. 1)
// URL : https://codeforces.com/problemset/problem/343/B
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
	string s;
	cin >> s;
	if (s.size() == 1) {cout << "No"; return;}
	stack<char> l;
	for (char c : s) {
		if (!l.empty() && l.top() == c) {l.pop();}
		else {l.push(c);}
	}
	cout << (l.empty() ? "Yes" : "No");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
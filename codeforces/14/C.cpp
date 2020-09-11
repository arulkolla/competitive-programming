
// Problem : C. Four Segments
// Contest : Codeforces - Codeforces Beta Round #14 (Div. 2)
// URL : https://codeforces.com/problemset/problem/14/C
// Memory Limit : 64 MB
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
	set<pair<int, int> > s;
	vector<pair<int, int> > v1, v2;
	int p1, p2;
	for (int i = 0; i < 8; i++) {
		cin >> p1 >> p2;
		s.insert(make_pair(p1, p2));
		if (i % 2) {v1.push_back(make_pair(p1, p2));}
		else {v2.push_back(make_pair(p1, p2));}
	}
	if (s.size() != 4) {cout << "NO";}
	else {
		set<int> f1, f2;
		for (pair<int, int> i : s) {
			f1.insert(i.first);
			f2.insert(i.second);
		}
		if (f1.size() == 2 && f2.size() == 2 ) {
			set<pair<double, double> > mids;
			for (int i = 0; i < 4; i++) {
				if (((v1[i].first != v2[i].first) && (v1[i].second != v2[i].second)) || ((v1[i].first == v2[i].first) && (v1[i].second == v2[i].second))) {cout << "NO"; return;}
				else {mids.insert(make_pair((v1[i].first + v2[i].first) / 2.0, (v1[i].second + v2[i].second) / 2.0));}
			}
			if (mids.size() != 4) {cout << "NO"; return;}
			cout << "YES";
		}
		else {cout << "NO";}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
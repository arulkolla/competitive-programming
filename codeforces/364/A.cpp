
// Problem : A. Matrix
// Contest : Codeforces - Codeforces Round #213 (Div. 1)
// URL : https://codeforces.com/problemset/problem/364/A
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

const int MAX = 4007;
const int MOD = 1000000007;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a[MAX];
	for (int i = 0; i < s.size(); i++) {
		a[i] = s[i] - '0';
	}
	int pref[MAX];
	pref[0] = 0;
	for (int i = 1; i < s.size() + 1; i++) {
		pref[i] = pref[i - 1] + a[i - 1];
	}
	map<int, long long> cnt;
	long long zcount = 0;
	for (int i = 0; i < s.size() + 1; i++) {
		for (int j = i + 1; j < s.size() + 1; j++) {
			cnt[pref[j] - pref[i]]++;
			if (pref[j] - pref[i] == 0) {zcount++;}
			// cout << pref[j] - pref[i] << " ";
		}
	} 
	long long res = 0;
	if (n == 0) {
		cout << zcount * s.size() * (s.size() + 1) - zcount * zcount;
		return;
	}
	for (int i = 1; i < ceil(sqrt(n)); i++) {
		if (n % i == 0) {
			res += cnt[i] * cnt[n / i];
		}
	}
	res *= 2;
	if (floor(sqrt(n)) == ceil(sqrt(n))) {
		res += cnt[(int)(sqrt(n))] * cnt[(int)(sqrt(n))];
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    solve();
}
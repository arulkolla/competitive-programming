
// Problem : B2. Cat Party (Hard Edition)
// Contest : Codeforces - Codeforces Round #558 (Div. 2)
// URL : https://codeforces.com/contest/1163/problem/B2
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
	int a[MAX], cnt[MAX] = {}, num[MAX] = {}, res = 1;
	int curr = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		num[cnt[a[i]]]++;
		if (cnt[a[i]] * num[cnt[a[i]]] == i && i != n) {res = i + 1;}
		else if (cnt[a[i]] * num[cnt[a[i]]] == i - 1) {res = i;}
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
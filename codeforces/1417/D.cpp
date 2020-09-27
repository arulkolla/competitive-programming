
// Problem : D. Make Them Equal
// Contest : Codeforces - Codeforces Round #673 (Div. 2)
// URL : https://codeforces.com/contest/1417/problem/D
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
	int n;
	cin >> n;
	int a[MAX];
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % n) {cout << -1 << endl; return;}
	cout << 3 * (n - 1) << endl;
    for (int i = 2; i <= n; i++) {
    	if (a[i] % i) {
    		cout << "1 " << i << " " << i - a[i] % i;
    		a[i] += i - a[i] % i;
    	}
    	else {
    		cout << "1 " << i << " 0";
    	}
    	cout << endl;
    	int x = a[i] / i;
    	cout << i << " 1 " << x << endl;
    	a[i] = 0;
    	a[1] += x * i;
    }
    for (int i = 2; i <= n; i++) {
    	cout << "1 " << i << " " << sum / n - a[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}
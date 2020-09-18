
// Problem : B. 4-point polyline
// Contest : Codeforces - MemSQL Start[c]UP 2.0 - Round 1
// URL : https://codeforces.com/contest/452/problem/B
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
	int n, m;
	cin >> n >> m;
	if (n == 0 || m == 0) {
		if (n == 0) {
			m = max(m, n);
			cout << 0 << " " << 1 << endl;
			cout << 0 << " " << m << endl;
			cout << 0 << " " << 0 << endl;
			cout << 0 << " " << m - 1 << endl;
		}
		else {
			m = max(m, n);
			cout << 1 << " " << 0 << endl;
			cout << m << " " << 0 << endl;
			cout << 0 << " " << 0 << endl;
			cout << m - 1 << " " << 0 << endl;
		}
		m = max(m, n);
	}
    else {
        long double d1 = sqrt(n * n + m * m) + 2 * sqrt((n-1) * (n-1) + m * m);
        long double d2 = sqrt(n * n + m * m) + 2 * sqrt((m-1) * (m-1) + n * n);
        long double d3 = 2 * sqrt(n * n + m * m) + max(m, n);
        if (d3 >= max(d1, d2)) {
        	if (n < m) {
        		cout << 0 << " " << 0 << endl;
        		cout << n << " " << m << endl;
        		cout << n << " " << 0 << endl;
        		cout << 0 << " " << m << endl;
        	}
        	else {
        		cout << 0 << " " << 0 << endl;
        		cout << n << " " << m << endl;
        		cout << 0 << " " << m << endl;
        		cout << n << " " << 0 << endl;
        	}
        }
        else if (n <= m) {
        	cout << n - 1 << " " << m << endl;
        	cout << 0 << " " << 0 << endl;
        	cout << n << " " << m << endl;
        	cout << 1 << " " << 0 << endl;
        }
        else {
        	cout << n << " " << m - 1 << endl;
        	cout << 0 << " " << 0 << endl;
        	cout << n << " " << m << endl;
        	cout << 0 << " " << 1 << endl;
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
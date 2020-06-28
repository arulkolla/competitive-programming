#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    unsigned long long a[MAX], b[MAX], t, currA = 0, currB = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        currA += t;
        a[i] = currA;
    }
    for (int i = 1; i <= m; i++) {
        cin >> t;
        currB += t;
        b[i] = currB;
    }
    a[0] = 0; b[0] = 0;
    unsigned long long mx = 0, ind = m;
    for (int i = 0; i <= n; i++) {
        if (a[i] > k) {break;}
        while (b[ind] > k - a[i]) {ind--;}
        mx = max(mx, i + ind);
    }
    cout << mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}
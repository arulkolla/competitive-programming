#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    long long n, c, prod = 1, o = 0, e = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        prod *= (c > 0 ? 1 : -1);
        if (prod < 0) {o++;}
        else {e++;}
    }
    cout << e * o << " " << n * (n+1) / 2 - e * o;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt;
//    cin >> tt;
//    for (int i = 1; i <= tt; i++) {
//        solve();
//        cout << endl;
//    }
    solve();
}
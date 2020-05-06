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
    long long n;
    cin >> n;
    long long count = 0;
    long double k;
    while (n > 1) {
        k = (long double)floor((sqrt(24*n + 1) - 1) / 6.0);
        n -= (long long)(1.5 * k * k + 0.5 * k);
        count++;
    }
    cout << count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        solve();
        cout << endl;
    }
//    solve();
}
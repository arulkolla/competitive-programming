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
    long long k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    long long bigCount = min(k2, min(k5, k6));
    long long smallCount = min(k2 - bigCount, k3), sum = 0;
    cout << bigCount * 256 + smallCount * 32;
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
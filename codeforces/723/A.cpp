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
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    int minDist = 10000000;
    for (int i = 1; i <= 100; i++) {
        minDist = min(minDist, abs(x1-i)+abs(x2-i)+abs(x3-i));
    }
    cout << minDist;
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
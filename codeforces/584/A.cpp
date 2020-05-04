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
    int n, t;
    cin >> n >> t;
    if (t == 10 && n == 1) {cout << -1; return;}
    cout << t;
    if (t == 10) {
        for (int i = 1; i < n - 1; i++) {
            cout << 0;
        }
    }
    else {
        for (int i = 0; i < n - 1; i++) {
            cout << 0;
        }
    }
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
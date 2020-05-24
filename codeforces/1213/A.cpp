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
    int n;
    cin >> n;
    int t, x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x, x + n);
    unsigned long long cost, maxVal = ULLONG_MAX;
    for (int i = 0; i < n; i++) {
        cost = 0;
        for (int j = 0; j < n; j++) {
            if (abs(x[i] - x[j]) % 2 == 1) {
                cost += 1;
            }
        }
        maxVal = min(cost, maxVal);
    }
    cout << maxVal;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}
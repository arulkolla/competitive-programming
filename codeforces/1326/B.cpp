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
    int b[n], a[n], x[n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    a[0] = b[0];
    x[0] = 0; x[1] = max(0, a[0]);
    for (int i = 1; i < n - 1; i++) {
        a[i] = x[i] + b[i];
        x[i+1] = max(x[i], a[i]);
    }
    a[n-1] = x[n-1] + b[n-1];
    for (int i : a) {
        cout << i << " ";
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
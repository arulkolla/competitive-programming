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
    int n, k, b;
    cin >> n >> k;
    int a[10001] = {0};
    for (int i = 0; i < n; i++) {
        cin >> b;
        a[b]++;
    }
    int oddCount = 0;
    for (int i : a) {
        if (i % 2 == 1) {oddCount++;}
    }
    cout << n - oddCount/2;
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
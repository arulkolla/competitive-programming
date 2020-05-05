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
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {cout << 1; return;}
    int maxSeq = 0, curr;
    for (int i = 0; i < n - 1; i++) {
        curr = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[j-1]) {break;}
            else {curr++;}
        }
        maxSeq = max(maxSeq, curr);
    }
    cout << maxSeq;
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
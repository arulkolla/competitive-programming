#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n], dp[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0] = 1;
    int curr = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i-1]) {curr = 1; dp[i] = max(curr, dp[i-1]);}
        else {curr += 1; dp[i] = max(curr, dp[i-1]);}
    }
    cout << dp[n-1];
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
#define ull unsigned long long

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
    string s;
    cin >> s;
    int m, dp[s.size() - 1];
    cin >> m;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i+1]) {dp[i] = 1;}
        else {dp[i] = 0;}
    }
    for (int i = 1; i < s.size() - 1; i++) {
        dp[i] += dp[i-1];
    }
    int l, r;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        if (l == 1) {cout << dp[r - 2] << endl;}
        else {
            l -= 2; r -= 2;
            cout << dp[r] - dp[l] << endl;
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

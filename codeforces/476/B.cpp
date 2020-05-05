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
    string s, r;
    cin >> s;
    cin >> r;
    int pos = 0, dream = 0, count = 0;
    for (char c : s) {
        if (c == '+') {pos++;}
        if (c == '-') {pos--;}
    }
    for (char c : r) {
        if (c == '+') {dream++;}
        if (c == '-') {dream--;}
        if (c == '?') {count++;}
    }
    if (abs(dream - pos) > count) {cout << 0.0; return;}
    if (count == 0) {cout << 1.0; return;}
    if (count % 2 != abs(dream - pos) % 2) {cout << 0.0; return;}
    double dp[count+1][count+1];
    dp[0][0] = 1;
    int thingy = 0;
    for (int i = 1; i < count+1; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {dp[j][i-j] = dp[j][i-j-1]/2.0;}
            else if (j == i) {dp[j][i-j] = dp[j-1][i-j]/2.0;}
            else {dp[j][i-j] = (dp[j-1][i-j] + dp[j][i-j-1])/2.0;}
            if (i == count && j == (count - abs(dream-pos))/2) {
                cout << fixed << dp[j][i-j]; return;
            }
        }
    }
    for (int i = 0; i < count+1; i++) {
        for (int j = 0; j < count+1; j++) {
            cout << dp[i][j] << '\t';
        }
        cout << '\n';
    }
}

int main() {
    cout.precision(17);
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
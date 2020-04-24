#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int m, s;
    cin >> m >> s;
    int big[m], small[m];
    int scopy = s - 1;
    if (m == 1 && s < 10) {cout << s << " " << s; return;}
    if (s < 1 || 9 * m < s) {cout << "-1 -1"; return;}
    for (int i = 0; i < m; i++) {
        if (s >= 9) {big[i] = 9; s -= 9;}
        else {big[i] = s; s = 0;}
    }
    for (int i = m-1; i > 0; i--) {
        if (scopy > 9) {small[i] = 9; scopy -= 9;}
        else {small[i] = scopy; scopy = 0;}
    }
    small[0] = scopy + 1;
    for (int z : small) {
        cout << z;
    }
    cout << " ";
    for (int z : big) {
        cout << z;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    int tt;
//    cin >> tt;
//    for (int i = 1; i <= tt; i++) {
//        cout << "Case #" << i << ": ";
//        solve();
//        cout << endl;
//    }
    solve();
}
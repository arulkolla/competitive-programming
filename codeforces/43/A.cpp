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
    string s, t, s2;
    cin >> s;
    int count1 = 1, count2 = 0;
    for (int i = 1; i < n; i++) {
        cin >> t;
        if (s == t) {count1++;}
        else {count2++; s2 = t;}
    }
    if (count1 > count2) {cout << s;}
    else {cout << s2;}
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
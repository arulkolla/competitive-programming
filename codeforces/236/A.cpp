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
    string s;
    cin >> s;
    int array[26] = {};
    for (char i : s) {
        array[(int)i - (int)'a'] = 1;
    }
    int total = 0;
    for (int i : array) {
        if (i > 0) {total++;}
    }
    cout << (total % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!");
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
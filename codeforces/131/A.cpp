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
    bool caps = true;
    for (int i = 1; i < s.size(); i++) {
        if ((int)s[i] >= (int)'a') {caps = false;}
    }
    if (!caps) {cout << s; return;}
    for (int i = 0; i < s.size(); i++) {
        if ((int)s[i] >= (int)'a') {s[i] = toupper(s[i]);}
        else {s[i] = tolower(s[i]);}
    }
    cout << s;
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
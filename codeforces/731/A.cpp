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
    int sum = 0;
    int curr, prev;
    prev = 0;
    curr = s[0] - 'a';
    if (abs(curr - prev) > 13) {sum += 26 - abs(curr - prev);}
    else {sum += abs(curr - prev);}
    for (int i = 1; i < s.size(); i++) {
        prev = s[i-1] - 'a';
        curr = s[i] - 'a';
        if (abs(curr - prev) > 13) {sum += 26 - abs(curr - prev);}
        else {sum += abs(curr - prev);}
    }
    cout << sum;
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
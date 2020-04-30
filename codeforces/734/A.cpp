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
    string s;
    cin >> s;
    int count = 0;
    for (char c : s) {
        if (c == 'A') {count++;}
        else {count--;}
    }
    if (count == 0) {cout << "Friendship";}
    else if (count > 0) {cout << "Anton";}
    else {cout << "Danik";}
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